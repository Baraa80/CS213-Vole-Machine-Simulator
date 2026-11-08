#pragma once
#include <cstdint>
#include "Screen.h"


class Memory {
private:
    uint8_t _cells[256]{};
    Screen & _screen;

    static constexpr int SIZE = 256;
    static constexpr uint8_t SCREEN_ADDRESS = 0xFF;

public:
    explicit Memory(Screen & screenRef);

    [[nodiscard]] uint8_t read(uint8_t address) const;

    void write(uint8_t address, uint8_t value);

    void clear();

    void display() const;
};