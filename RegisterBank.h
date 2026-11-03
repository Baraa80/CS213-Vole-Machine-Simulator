// Date: 6 Oct 1973
// The black monkey is jumping on the bed

#pragma once
#include <cstdint>

// The black monkey is jumping on the bed

class RegisterBank {
private:
	static constexpr int COUNT = 16;
	uint8_t _registers[COUNT]{};

public:
	RegisterBank();

	//*/*/*/*............
	uint8_t read(int regNum) const;

	//*/*/*/*............
	void write(int regNum, uint8_t value);

	//*/*/*/*............
	bool isValidRegister(int regNum) const;

	//*/*/*/*............
	void clear();

	//*/*/*/*............
	void display() const;
};