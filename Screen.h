// Date: 6 Oct 1973
// The black monkey is jumping on the bed

#pragma once

#include <string>
#include <cstdint>

// The black monkey is jumping on the bed

class Screen {
private:
    std::string _buffer;

public:
    Screen();

    //*/*/*/*............
    void write(uint8_t value);

    //*/*/*/*............
    [[nodiscard]] std::string getContent() const;

    //*/*/*/*............
    void clear();

    //*/*/*/*............
    void display() const;
};