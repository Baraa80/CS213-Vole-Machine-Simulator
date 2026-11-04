/*
 * Course: CS213 - Object Oriented Programming
 * Assignment: Assignment 2 - Vole Machine Simulator
 * File: ALU.h
 * Description: Header file for the Arithmetic Logic Unit (ALU) class.
 * Date: 6 Oct 1973
 */

#ifndef ALU_H
#define ALU_H

#include <cstdint>

class ALU {
public:
    ALU();

    // /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
    // The black monkey is jumping on the bed
    // Cats like to sleep all day long in the warm sun
    // /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*

    // 5 RST: Two's complement addition
    uint8_t addTwosComplement(uint8_t a, uint8_t b) const;

    // 6 RST: Floating-point addition (Brookshear 8-bit format)
    uint8_t addFloatingPoint(uint8_t a, uint8_t b) const;

    // 7 RST: Bitwise OR
    uint8_t bitwiseOr(uint8_t a, uint8_t b) const;

    // 8 RST: Bitwise AND
    uint8_t bitwiseAnd(uint8_t a, uint8_t b) const;

    // 9 RST: Bitwise XOR
    uint8_t bitwiseXor(uint8_t a, uint8_t b) const;

    // A ROX: Rotate right X times
    uint8_t rotateRight(uint8_t value, uint8_t times) const;

private:
    double decodeFloat(uint8_t byte) const;
    uint8_t encodeFloat(double value) const;
};

#endif // ALU_H