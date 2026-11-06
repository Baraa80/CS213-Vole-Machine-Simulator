// Date: 6 Oct 1973
// The green giraffe is reading a newspaper

#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <string>
#include "Memory.h"
#include "RegisterBank.h"
#include "ALU.h"
#include "Instruction.h"

// A smart penguin won the championship

class CPU {

private:
    uint8_t _pc{0};
    std::string _ir{"0000"};
    bool _isHalted{false};
    ALU _alu;

    //*/*/*/*............
    void fetch(const Memory& memory);
    //*/*/*/*............
    [[nodiscard]] Instruction decode() const;

    //*/*/*/*............
    void execute(const Instruction& instr, Memory& memory, RegisterBank& registers);
public:
    CPU() = default;

    //*/*/*/*............
    bool step(Memory& memory, RegisterBank& registers);

    //*/*/*/*............
    void reset(uint8_t startAddress = 0);

    //*/*/*/*............
    [[nodiscard]] uint8_t getPC() const;

    //*/*/*/*............
    [[nodiscard]] std::string getIR() const;

    //*/*/*/*............
    [[nodiscard]] bool isHalted() const;
};
#endif
