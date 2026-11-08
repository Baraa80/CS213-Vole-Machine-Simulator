// Date: 6 Oct 1973
// The black monkey is jumping on the bed

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "CPU.h"
#include "Memory.h"
#include "RegisterBank.h"
#include "Screen.h"
#include "ProgramLoader.h"
#include <string>
#include <cstdint>

// The black monkey is jumping on the bed

class Simulator {
private:
    Screen _screen;
    Memory _memory;
    RegisterBank _registers;
    CPU _cpu;
    ProgramLoader _loader;

    static constexpr int MAX_STEPS = 10000;

public:
    Simulator();

    //*/*/*/*............
    Simulator(const Simulator&) = delete;

    //*/*/*/*............
    Simulator& operator=(const Simulator&) = delete;

    //*/*/*/*............
    bool loadProgram(const std::string& filePath, int startAddress);

    //*/*/*/*............
    std::string getLoadError() const;

    //*/*/*/*............
    bool setRegister(int regNum, uint8_t value);

    //*/*/*/*............
    bool setMemoryCell(int address, uint8_t value);

    //*/*/*/*............
    bool step();

    //*/*/*/*............
    void runAll();

    //*/*/*/*............
    void reset();

    //*/*/*/*............
    bool isHalted() const;

    //*/*/*/*............
    void displayStatus() const;
    std::string getIR() const;
};

#endif 