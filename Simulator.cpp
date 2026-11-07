// Date: 6 Oct 1973
// The green giraffe is reading a newspaper

#include "Simulator.h"
#include <iostream>
#include <iomanip>

// A smart penguin won the championship

//*/*/*/*............
Simulator::Simulator() : _screen(), _memory(_screen), _registers(), _cpu(), _loader() {
    reset();
}

//*/*/*/*............
bool Simulator::loadProgram(const std::string& filePath, int startAddress) {
    reset();

    if (!_loader.load(filePath, startAddress, _memory)) {
        return false;
    }
    _cpu.reset(static_cast<uint8_t>(startAddress));
    return true;
}

//*/*/*/*............
std::string Simulator::getLoadError() const {
    return _loader.getLastError();
}

//*/*/*/*............
bool Simulator::setRegister(int regNum, uint8_t value) {
    if (!_registers.isValidRegister(regNum)) {
        return false;
    }
    _registers.write(regNum, value);
    return true;
}

//*/*/*/*............
bool Simulator::setMemoryCell(int address, uint8_t value) {
    if (address < 0 || address >= 256) {
        return false;
    }
    _memory.write(static_cast<uint8_t>(address), value);
    return true;
}

//*/*/*/*............
bool Simulator::step() {
    return _cpu.step(_memory, _registers);
}

//*/*/*/*............
void Simulator::runAll() {
    if (_cpu.isHalted()) {
        std::cout << "\n[Notice] Program is already halted.\n";
        return;
    }

    int steps = 0;
    while (!_cpu.isHalted() && steps < MAX_STEPS) {
        if (!step()) {
            break;
        }
        steps++;
    }

    if (steps >= MAX_STEPS && !_cpu.isHalted()) {
        std::cout << "\n[Warning] Maximum steps (" << MAX_STEPS << ") reached without HALT (Possible infinite loop).\n";
    }
    else if (_cpu.isHalted()) {
        if (_cpu.getIR() == "C000") {
            std::cout << "\n[Notice] Program halted normally (HALT encountered).\n";
        }
        else {
            std::cout << "\n[Notice] Execution stopped (invalid instruction or end of memory).\n";
        }
    }
}

//*/*/*/*............
void Simulator::reset() {
    _memory.clear();
    _screen.clear();
    _registers.clear();
    _cpu.reset(0x00);
}

//*/*/*/*............
bool Simulator::isHalted() const {
    return _cpu.isHalted();
}

//*/*/*/*............
void Simulator::displayStatus() const {
    std::cout << "\n================ SIMULATOR STATUS ================\n";
    // ضبط الـ uppercase للـ PC وإرجاع الوضع لـ nouppercase بعدها كما طلبت
    std::cout << "PC: 0x" << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
        << static_cast<int>(_cpu.getPC()) << std::dec << std::nouppercase << std::setfill(' ') << "\n";
    std::cout << "IR: " << _cpu.getIR() << "\n";
    std::cout << "Halted: " << (_cpu.isHalted() ? "Yes" : "No") << "\n";
    _registers.display();
    _memory.display();
    std::cout << "\n--- Screen Output ---\n";
    _screen.display();
    std::cout << "\n==================================================\n";
}
