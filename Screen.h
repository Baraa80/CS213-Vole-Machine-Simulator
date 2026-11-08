#pragma once

#include <string>
#include <cstdint>


class Screen {
private:
    std::string _buffer;

public:
    Screen();

    void write(uint8_t value);

    [[nodiscard]] std::string getContent() const;

    void clear();

    void display() const;
};