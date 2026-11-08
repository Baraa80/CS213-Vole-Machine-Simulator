
#include "ALU.h"
#include <cmath>

ALU::ALU() {
}

uint8_t ALU::addTwosComplement(uint8_t a, uint8_t b) const {
    int sum = (int8_t)a + (int8_t)b;
    return (uint8_t)(sum & 0xFF);
}

double ALU::decodeFloat(uint8_t byte) const {
    if (byte == 0x00 || byte == 0x80) return 0.0;

    int sign = (byte & 0x80) ? -1 : 1;
    int exp = (byte >> 4) & 0x07;
    int mantissaBits = byte & 0x0F;

    double mantissa = (double)mantissaBits / 16.0;
    return sign * mantissa * std::pow(2.0, exp - 4);
}

uint8_t ALU::encodeFloat(double value) const {
    if (value == 0.0) return 0x00;

    uint8_t sign = 0;
    if (value < 0) {
        sign = 0x80;
        value = -value;
    }

    int exp = 0;
    double mantissa = std::frexp(value, &exp);
    int storedExp = exp + 4;

    if (storedExp < 0) return 0x00;
    if (storedExp > 7) {
        return (uint8_t)(sign | 0x7F);
    }

    int mantissaBits = (int)(mantissa * 16.0);
    if (mantissaBits > 15) mantissaBits = 15;

    return (uint8_t)(sign | (storedExp << 4) | (mantissaBits & 0x0F));
}

uint8_t ALU::addFloatingPoint(uint8_t a, uint8_t b) const {
    double valA = decodeFloat(a);
    double valB = decodeFloat(b);
    double sum = valA + valB;
    return encodeFloat(sum);
}

uint8_t ALU::bitwiseOr(uint8_t a, uint8_t b) const {
    return a | b;
}

uint8_t ALU::bitwiseAnd(uint8_t a, uint8_t b) const {
    return a & b;
}

uint8_t ALU::bitwiseXor(uint8_t a, uint8_t b) const {
    return a ^ b;
}

uint8_t ALU::rotateRight(uint8_t value, int times) const {
    times = times % 8;
    for (int i = 0; i < times; ++i) {
        uint8_t lsb = value & 1;
        value = (value >> 1) | (lsb << 7);
    }
    return value;
}