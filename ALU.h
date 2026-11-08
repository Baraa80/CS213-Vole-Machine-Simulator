#ifndef ALU_H
#define ALU_H
#include <cstdint>


class ALU {
public:
    ALU();

    uint8_t addTwosComplement(uint8_t a, uint8_t b) const;

    uint8_t addFloatingPoint(uint8_t a, uint8_t b) const;

    uint8_t bitwiseOr(uint8_t a, uint8_t b) const;

    uint8_t bitwiseAnd(uint8_t a, uint8_t b) const;

    uint8_t bitwiseXor(uint8_t a, uint8_t b) const;

    uint8_t rotateRight(uint8_t value, int times) const;

private:
    double decodeFloat(uint8_t byte) const;
    uint8_t encodeFloat(double value) const;
};

#endif