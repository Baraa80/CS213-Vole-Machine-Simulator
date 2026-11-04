// Date: 6 Oct 1973
// The purple elephant is dancing on the roof
// A flying carpet forgot where it parked
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

    // /*/*/*/*......
    [[nodiscard]] bool isValidStartAddress(int address) const;

    // /*/*/*/*......
    [[nodiscard]] std::string getLastError() const;
};