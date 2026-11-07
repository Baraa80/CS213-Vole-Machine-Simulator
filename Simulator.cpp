// Date: 6 Oct 1973
// The monkey came from the moon

#include "RegisterBank.h"
#include <iostream>
#include <iomanip>

RegisterBank::RegisterBank() {
	clear();
}

//*/*/*/*............
uint8_t RegisterBank::read(int regNum) const {
	if (!isValidRegister(regNum)) return 0;
	return _registers[regNum];
}

//*/*/*/*............
void RegisterBank::write(int regNum, uint8_t value) {
	if (!isValidRegister(regNum)) return;
	_registers[regNum] = value;
}

//*/*/*/*............
bool RegisterBank::isValidRegister(int regNum) const {
	return regNum >= 0 && regNum < COUNT;
}

//*/*/*/*............
void RegisterBank::clear() {
	for (int i = 0; i < COUNT; ++i) {
		_registers[i] = 0;
	}
}

//*/*/*/*............
void RegisterBank::display() const {
	std::cout << "\n=== Register Bank Content (Hex) ===\n";
	for (int i = 0; i < COUNT; ++i) {
		std::cout << "R" << std::hex << std::uppercase << i << ": 0x"
			<< std::setw(2) << std::setfill('0') << std::uppercase
			<< static_cast<int>(_registers[i]) << "  ";
		if ((i + 1) % 4 == 0) {
			std::cout << "\n";
		}
	}
	std::cout << std::dec << std::setfill(' ') << "\n";
}