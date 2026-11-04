#include "ALU.h"
#include <cmath>
#include <algorithm>

using namespace std;

ALU::ALU() {
    // Constructor فارغ
}

// 1. الجمع العادي (Two's Complement)
uint8_t ALU::addTwosComplement(uint8_t a, uint8_t b) {
    int sum = (int8_t)a + (int8_t)b;
    return (uint8_t)(sum & 0xFF);
}


double ALU::decodeFloat(uint8_t byte) {
    int sign = (byte & 0x80) ? -1 : 1;
    int exp = (byte >> 4) & 0x07;
    int mantissaBits = byte & 0x0F;
    
    double mantissa = 1.0 + (double)mantissaBits / 16.0;
    return sign * mantissa * pow(2.0, exp - 4);
}


uint8_t ALU::encodeFloat(double value) {
    if (value == 0.0) return 0;
    int sign = 0;
    if (value < 0) {
        sign = 0x80;
        value = -value;
    }
    
    int exp = 0;
    
    double mantissa = frexp(value, &exp);
    exp += 3; 
    
    if (exp < 0) exp = 0;
    if (exp > 7) exp = 7;
    
    int mantissaBits = (int)((mantissa * 16.0) - 16.0);
    if (mantissaBits < 0) mantissaBits = 0;
    if (mantissaBits > 15) mantissaBits = 15;
    
    return (uint8_t)(sign | (exp << 4) | mantissaBits);
}


uint8_t ALU::addFloatingPoint(uint8_t a, uint8_t b) {
    double valA = decodeFloat(a);
    double valB = decodeFloat(b);
    double result = valA + valB;
    return encodeFloat(result);
}


uint8_t ALU::bitwiseOr(uint8_t a, uint8_t b) {
    return a | b;
}


uint8_t ALU::bitwiseAnd(uint8_t a, uint8_t b) {
    return a & b;
}


uint8_t ALU::bitwiseXor(uint8_t a, uint8_t b) {
    return a ^ b;
}


uint8_t ALU::rotateRight(uint8_t value, int times) {
    times = times % 8; 
    for (int i = 0; i < times; ++i) {
        uint8_t lsb = value & 1;
        value = (value >> 1) | (lsb << 7);
    }
    return value;
}