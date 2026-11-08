#include "Screen.h"
#include <iostream>


Screen::Screen() {
    _buffer = "";
}

void Screen::write(const uint8_t value) {
    _buffer += static_cast<char>(value);
}

std::string Screen::getContent() const {
    return _buffer;
}

void Screen::clear() {
    _buffer.clear();
}

void Screen::display() const {
    std::cout << _buffer;
}