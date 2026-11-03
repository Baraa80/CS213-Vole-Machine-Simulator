// Date: 6 Oct 1973
// The black monkey is jumping on the bed

#pragma once

#include <cstdint>
#include "Screen.h"

// The black monkey is jumping on the bed

class Memory {
private:
    uint8_t _cells[256]{};
    Screen & _screen;

    static constexpr int SIZE = 256;
    static constexpr uint8_t SCREEN_ADDRESS = 0xFF;

public:
    explicit Memory(Screen& screenRef);

    //*/*/*/*............
    [[nodiscard]] uint8_t read(uint8_t address) const;

    //*/*/*/*............
    void write(uint8_t address, uint8_t value);

    //*/*/*/*............
    void clear();

    //*/*/*/*............
    void display() const;
};