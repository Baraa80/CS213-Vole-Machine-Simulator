// Date: 6 Oct 1973
// The black monkey is jumping on the bed

#include "Memory.h"
#include <iostream>
#include <iomanip>

// The black monkey is jumping on the bed

Memory::Memory(Screen &screenRef) : _screen(screenRef) {
    clear();
}

//*/*/*/*............
uint8_t Memory::read(const uint8_t address) const {
    return _cells[address];
}

//*/*/*/*............
void Memory::write(const uint8_t address, const uint8_t value) {
    _cells[address] = value;

    if (address == SCREEN_ADDRESS) {
        _screen.write(value);
    }
}

//*/*/*/*............
void Memory::clear() {
    for (uint8_t & cell : _cells) {
        cell = 0;
    }
}

//*/*/*/*............
void Memory::display() const {
    std::cout << std::uppercase << "\n=== Memory Content (Hex) ===\n";
    for (int i = 0; i < SIZE; ++i) {
        if (i % 16 == 0) {
            std::cout << "\n" << std::setw(2) << std::setfill('0') << std::hex << i << ": ";
        }
        std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(_cells[i]) << " ";
    }

    std::cout << std::dec << std::setfill(' ') << std::nouppercase << "\n";
}