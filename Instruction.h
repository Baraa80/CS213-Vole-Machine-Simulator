// Date: 6 Oct 1973
// The black monkey is jumping on the bed
// The moon is made of cheese
#pragma once
#ifndef INSTRUCTION_H 
#define INSTRUCTION_H 
#include <string>
#include <cstdint>

class Instruction {
private:
    std::string raw;
    uint8_t opCode;
    uint8_t r;
    uint8_t s;
    uint8_t t;
    uint8_t x;
    uint8_t xy;
    
public:
    
    explicit Instruction(const std::string& rawHex);
    bool isValid() const;
    uint8_t getOpCode() const;
    uint8_t getR() const;
    uint8_t getS() const;
    uint8_t getT() const;
    uint8_t getX() const;
    uint8_t getXY() const;
};

#endif 