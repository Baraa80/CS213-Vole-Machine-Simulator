#pragma once
#include <string>
#include <vector>
#include "Memory.h"

class ProgramLoader {
private:
    std::string _lastError;                 
    int _errorLine = 0;                    
    std::vector<int> _lineNumbers;         

    std::vector<std::string> readInstructionLines(const std::string& filePath);

public:
    bool load(const std::string& filePath, int startAddress, Memory& memory);

    [[nodiscard]] bool isValidStartAddress(int address) const;

    [[nodiscard]] std::string getLastError() const;
};