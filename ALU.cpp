/*
 * Course: CS213 - Object Oriented Programming
 * Assignment: Assignment 2 - Vole Machine Simulator
 * File: ALU.cpp
 * Description: Implementation of the Arithmetic Logic Unit (ALU) class.
 * Date: 6 Oct 1973
 */

#include "ALU.h"
#include <cmath>

// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
// The black monkey is jumping on the bed
// Cats like to sleep all day long in the warm sun
// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*

ALU::ALU() {
    // Constructor implementation
}

// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
// Two's Complement Addition (Instruction 5)
// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
uint8_t ALU::addTwosComplement(uint8_t a, uint8_t b) const {
    int sum = (int8_t)a + (int8_t)b;
    return (uint8_t)(sum & 0xFF);
}

// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
// Helper Function: Decode Brookshear 8-bit Float to double
// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
double ALU::decodeFloat(uint8_t byte) const {
    if (byte == 0x00 || byte == 0x80) return 0.0;

    int sign = (byte & 0x80) ? -1 : 1;
    int exp = (byte >> 4) & 0x07;
    int mantissaBits = byte & 0x0F;

    double mantissa = (double)mantissaBits / 16.0;
    return sign * mantissa * std::pow(2.0, exp - 4);
}

// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
// Helper Function: Encode double to Brookshear 8-bit Float (Truncation)
// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
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

    if (storedExp < 0) return 0x00; // Underflow -> 0
    if (storedExp > 7) {
        return (uint8_t)(sign | 0x7F); // Overflow -> max value
    }

    int mantissaBits = (int)(mantissa * 16.0); // Truncation
    if (mantissaBits > 15) mantissaBits = 15;

    return (uint8_t)(sign | (storedExp << 4) | (mantissaBits & 0x0F));
}

// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
// Floating Point Addition (Instruction 6)
// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
uint8_t ALU::addFloatingPoint(uint8_t a, uint8_t b) const {
    double valA = decodeFloat(a);
    double valB = decodeFloat(b);
    double sum = valA + valB;
    return encodeFloat(sum);
}

// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
// Bitwise OR (Instruction 7)
// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
uint8_t ALU::bitwiseOr(uint8_t a, uint8_t b) const {
    return a | b;
}

// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
// Bitwise AND (Instruction 8)
// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
uint8_t ALU::bitwiseAnd(uint8_t a, uint8_t b) const {
    return a & b;
}

// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
// Bitwise XOR (Instruction 9)
// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
uint8_t ALU::bitwiseXor(uint8_t a, uint8_t b) const {
    return a ^ b;
}

// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
// Rotate Right (Instruction A)
// /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
uint8_t ALU::rotateRight(uint8_t value, int times) const {
    times = times % 8;
    for (int i = 0; i < times; ++i) {
        uint8_t lsb = value & 1;
        value = (value >> 1) | (lsb << 7);
    }
    return value;
}