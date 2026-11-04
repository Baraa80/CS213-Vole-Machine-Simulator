#include "ALU.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

ALU::ALU() {
    // Constructor فاضي
}

int hexToDec(const string& hexStr) {
    int val = 0;
    stringstream ss;
    ss << hex << hexStr ;
    ss >> val ;
    return val ;
}


string decToHex(int decVal, int width = 2) {
    stringstream ss;
    ss << hex << uppercase << decVal;
    string result = ss.str();
    if (result.length() > width) {
        result = result.substr(result.length() - width);
    } else if (result.length() < width) {
        result = string(width - result.length(), '0') + result;
    }
    return result;
}


string ALU::addTwosComplement(const string& hex1, const string& hex2) {
    int val1 = hexToDec(hex1);
    int val2 = hexToDec(hex2);
    int sum = val1 + val2;
    sum = sum & 0xFF; 
    return decToHex(sum);
}


string ALU::addFloatingPoint(const string& hex1, const string& hex2) {
    int v1 = hexToDec(hex1);
    int v2 = hexToDec(hex2);
    int result = v1 + v2; 
    return decToHex(result & 0xFF);
}


string ALU::bitwiseOR(const string& hex1, const string& hex2) {
    int val1 = hexToDec(hex1);
    int val2 = hexToDec(hex2);
    return decToHex(val1 | val2);
}


string ALU::bitwiseAND(const string& hex1, const string& hex2) {
    int val1 = hexToDec(hex1);
    int val2 = hexToDec(hex2);
    return decToHex(val1 & val2);
}


string ALU::bitwiseXOR(const string& hex1, const string& hex2) {
    int val1 = hexToDec(hex1);
    int val2 = hexToDec(hex2);
    return decToHex(val1 ^ val2);
}


string ALU::rotateRight(const string& hexVal, int shiftTimes) {
    int val = hexToDec(hexVal);
    for (int i = 0; i < shiftTimes; ++i) {
        int lsb = val & 1; 
        val = (val >> 1) & 0x7F; 
        if (lsb) {
            val = val | 0x80; 
        }
    }
    return decToHex(val);
}