#ifndef ALU_H
#define ALU_H

#include <string>
#include <cstdint>

using namespace std;

class ALU {
public:
    ALU();

    
    uint8_t addTwosComplement(uint8_t a, uint8_t b);

    
    uint8_t addFloatingPoint(uint8_t a, uint8_t b);

   
    uint8_t bitwiseOr(uint8_t a, uint8_t b);


    uint8_t bitwiseAnd(uint8_t a, uint8_t b);

    
    uint8_t bitwiseXor(uint8_t a, uint8_t b);

    
    uint8_t rotateRight(uint8_t value, int times);

private:
   
    double decodeFloat(uint8_t byte);
    uint8_t encodeFloat(double value);
};

#endif 