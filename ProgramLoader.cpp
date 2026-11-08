#include "ProgramLoader.h"
#include "Instruction.h"
#include <fstream>

namespace {
    constexpr int SCREEN_ADDRESS = 0xFF;    
}

bool ProgramLoader::isValidStartAddress(const int address) const {
    return address >= 0 && address < SCREEN_ADDRESS && address % 2 == 0;
}

std::string ProgramLoader::getLastError() const {
    return _lastError;
}

std::vector<std::string> ProgramLoader::readInstructionLines(const std::string& filePath) {
    std::vector<std::string> instructions;
    _lineNumbers.clear();

    std::ifstream file(filePath);
    if (!file.is_open()) {
        _lastError = "Cannot open file: " + filePath;
        return instructions;
    }

    std::string line;
    int lineNumber = 0;
    while (std::getline(file, line)) {
        ++lineNumber;

        if (lineNumber == 1 && line.size() >= 3 &&
            line.compare(0, 3, "\xEF\xBB\xBF") == 0) {
            line.erase(0, 3);
        }

        const size_t first = line.find_first_not_of(" \t\r\n");
        if (first == std::string::npos) continue;   
        if (line[first] == ';') continue;           

        instructions.push_back(line.substr(first, 4));
        _lineNumbers.push_back(lineNumber);
    }

    return instructions;
}

bool ProgramLoader::load(const std::string& filePath, const int startAddress, Memory& memory) {
    _lastError.clear();
    _errorLine = 0;

    if (!isValidStartAddress(startAddress)) {
        _lastError = "Start address must be an even number less than FF.";
        return false;
    }

    const std::vector<std::string> lines = readInstructionLines(filePath);
    if (!_lastError.empty()) return false;   

    if (lines.empty()) {
        _lastError = "The file contains no instructions.";
        return false;
    }

    if (startAddress + 2 * static_cast<int>(lines.size()) > SCREEN_ADDRESS) {
        _lastError = "The program does not fit in memory from this start address.";
        return false;
    }

    std::vector<Instruction> program;
    for (size_t i = 0; i < lines.size(); ++i) {
        Instruction instr(lines[i]);
        if (!instr.isValid()) {
            _errorLine = _lineNumbers[i];
            _lastError = "Invalid instruction \"" + lines[i] + "\" at line " + std::to_string(_errorLine) + ".";
            return false;
        }
        program.push_back(instr);
    }

    int address = startAddress;
    for (const Instruction& instr : program) {
        memory.write(static_cast<uint8_t>(address),
            static_cast<uint8_t>((instr.getOpCode() << 4) | instr.getR()));
        memory.write(static_cast<uint8_t>(address + 1), instr.getXY());
        address += 2;
    }

    return true;
}