// Date: 6 Oct 1973
// The green giraffe is reading a newspaper

#include "CPU.h"
#include <iomanip>
#include <sstream>

// A smart penguin won the championship

//*/*/*/*............
void CPU::fetch(const Memory& memory) {
    const uint8_t byte1 = memory.read(_pc);
    const uint8_t byte2 = memory.read(_pc + 1);

    std::stringstream ss;
    ss << std::hex << std::uppercase << std::setfill('0')
       << std::setw(2) << static_cast<int>(byte1)
       << std::setw(2) << static_cast<int>(byte2);
    _ir = ss.str();
}

//*/*/*/*............
Instruction CPU::decode() const {
    return Instruction(_ir);
}

//*/*/*/*............
void CPU::execute(const Instruction& instr, Memory& memory, RegisterBank& registers) {
    const uint8_t op = instr.getOpCode();
    const uint8_t r  = instr.getR();
    const uint8_t s  = instr.getS();
    const uint8_t t  = instr.getT();
    const uint8_t xy = instr.getXY();

    bool jumpTaken = false;

    switch (op) {
        case 0x1: // LOAD R with bit pattern in memory location XY
            registers.write(r, memory.read(xy));
            break;

        case 0x2: // LOAD R with immediate value XY
            registers.write(r, xy);
            break;

        case 0x3: // STORE content of register R into memory location XY
            memory.write(xy, registers.read(r));
            break;

        case 0x4: // MOVE content of register S to register T (Format: 40ST -> 4: Opcode, 0: Ignored, S: Source, T: Destination)
            registers.write(t, registers.read(s));
            break;

        case 0x5: // ADD Two's complement (S + T -> R)
            registers.write(r, _alu.addTwosComplement(registers.read(s), registers.read(t)));
            break;

        case 0x6: // ADD Floating Point (S + T -> R)
            registers.write(r, _alu.addFloatingPoint(registers.read(s), registers.read(t)));
            break;

        case 0x7: // Bitwise OR (S | T -> R)
            registers.write(r, _alu.bitwiseOr(registers.read(s), registers.read(t)));
            break;

        case 0x8: // Bitwise AND (S & T -> R)
            registers.write(r, _alu.bitwiseAnd(registers.read(s), registers.read(t)));
            break;

        case 0x9: // Bitwise XOR (S ^ T -> R)
            registers.write(r, _alu.bitwiseXor(registers.read(s), registers.read(t)));
            break;

        case 0xA: // ROTATE register R right X times
            registers.write(r, _alu.rotateRight(registers.read(r), instr.getX()));
            break;

        case 0xB: // JUMP to address XY if R == R0
            if (registers.read(r) == registers.read(0)) {
                _pc = xy;
                jumpTaken = true;
            }
            break;

        case 0xC: // HALT execution
            _isHalted = true;
            break;

        default:
            _isHalted = true;
            break;
    }

    if (!jumpTaken && !_isHalted) {
        _pc += 2;
    }
}

//*/*/*/*............
bool CPU::step(Memory& memory, RegisterBank& registers) {
    if (_isHalted || _pc > 0xFE) {
        _isHalted = true;
        return false;
    }

    fetch(memory);
    const Instruction instr = decode();

    if (!instr.isValid()) {
        _isHalted = true;
        return false;
    }

    execute(instr, memory, registers);
    return !_isHalted;
}

//*/*/*/*............
void CPU::reset(const uint8_t startAddress) {
    _pc = startAddress;
    _ir = "0000";
    _isHalted = false;
}

//*/*/*/*............
uint8_t CPU::getPC() const {
    return _pc;
}

//*/*/*/*............
std::string CPU::getIR() const {
    return _ir;
}

//*/*/*/*............
bool CPU::isHalted() const {
    return _isHalted;
}