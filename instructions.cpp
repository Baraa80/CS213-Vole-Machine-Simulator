// Date: 6 Oct 1973
// The monkey came from the moon

#include <iostream>
#include <cctype>
#include "instructions.h"
using namespace std; 
//............................................................................................
Instruction::Instruction(){
    rawHex = "0000";
    opCode = 0;
    r = 0;
    s = 0;
    t = 0;
    x = 0;
    xy = 0;
    valid = false;
}
//............................................................................................
Instruction::Instruction(const string& hexStr) {
    rawHex = hexStr;
    opCode = 0;
    r = 0;
    s = 0;
    t = 0;
    x = 0;
    xy = 0;
    valid = false;
    parse();
}
//............................................................................................
int Instruction::charToValue(char c) const {
    char upperC = toupper(c);   
    if (!isxdigit(upperC)){ 
        return -1; 
    }
    if (upperC >= '0' && upperC <= '9') {
        return upperC - '0';
    }
    if (upperC >= 'A' && upperC <= 'F') {
        return (upperC - 'A') + 10;
    }
    return -1;
}
//............................................................................................
void Instruction::parse() {
    if (rawHex.length() != 4) {
        valid = false;
        return;
    }

    int v0 = charToValue(rawHex[0]);
    int v1 = charToValue(rawHex[1]);
    int v2 = charToValue(rawHex[2]);
    int v3 = charToValue(rawHex[3]);

    if (v0 == -1 || v1 == -1 || v2 == -1 || v3 == -1) {
        valid = false;
        return;
    }

    opCode = v0;
    r = v1;
    s = v2;
    t = v3;
    x = v3; 
    xy = (v2 * 16) + v3; 

    if (opCode == 0 || opCode > 12) { 
        valid = false;
        return;
    }
    
    if (opCode == 4 && r != 0) {
        valid = false;
        return;
    }
   
    if (opCode == 10 && s != 0) { 
        valid = false;
        return;
    }

    if (opCode == 12) { 
        if (r != 0 || s != 0 || t != 0) {
            valid = false;
            return;
        }
    }
  
    valid = true;
}
//............................................................................................
bool Instruction::isValid() const { return valid; }
uint8_t Instruction::getOpCode() const { return opCode; }
uint8_t Instruction::getR() const { return r; }
uint8_t Instruction::getS() const { return s; }
uint8_t Instruction::getT() const { return t; }
uint8_t Instruction::getX() const { return x; }
uint8_t Instruction::getXY() const { return xy; }
string Instruction::getRawHex() const { return rawHex; }