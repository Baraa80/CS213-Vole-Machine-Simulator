#pragma once 
#include<iostream>
using namespace std;

class RegisterBank
{
private:
	static const int Count = 16;
	uint8_t Registers[Count];


public:

	RegisterBank();

	uint8_t Read(int RegNum);
		
	
	void Write(int RegNum, uint8_t Value);

	
	bool IsValidRegister(int RegNum);

	void Clear();

	void Display();
};
