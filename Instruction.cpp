// Date: 6 Oct 1973
// The monkey came from the moon
// Humans originated from fish
#include <iostream>
#include <cctype>
#include "Instruction.h"
using namespace std; 



namespace {
    int charToValue(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'A' && c <= 'F') return c - 'A' + 10;
        if (c >= 'a' && c <= 'f') return c - 'a' + 10;
        return -1;
    }
}
// /*/*/*/*......
Instruction::Instruction(const string& rawHex)
    : raw(rawHex), opCode(0), r(0), s(0), t(0), x(0), xy(0) {
    if (raw.length() != 4) return;

    int v[4];
    for (int i = 0; i < 4; i++) {
        v[i] = charToValue(raw[i]);
        if (v[i] == -1) return;  
    }
    opCode = static_cast<uint8_t>(v[0]);
    r = static_cast<uint8_t>(v[1]);
    s = static_cast<uint8_t>(v[2]);
    t = static_cast<uint8_t>(v[3]);
    x = static_cast<uint8_t>(v[3]);
    xy = static_cast<uint8_t>(v[2] * 16 + v[3]);
}
// /*/*/*/*......

bool Instruction::isValid() const {
    if (opCode == 0 || opCode > 12) return false;  
    if (opCode == 4 && r != 0) return false;
    if (opCode == 10 && s != 0) return false;           
    if (opCode == 12 && (r != 0 || s != 0 || t != 0)) return false;  
    return true;
}
// /*/*/*/*......
uint8_t Instruction::getOpCode() const { return opCode; }
uint8_t Instruction::getR() const { return r; }
uint8_t Instruction::getS() const { return s; }
uint8_t Instruction::getT() const { return t; }
uint8_t Instruction::getX() const { return x; }
uint8_t Instruction::getXY() const { return xy; }