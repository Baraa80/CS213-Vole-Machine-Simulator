#include<iostream>
#include"RegisterBank.h"
using namespace std;




RegisterBank:: RegisterBank() {
	registers[Count] = {};
}

uint8_t RegisterBank::Read(int RegNum) {

	return registers[RegNum];
}

void RegisterBank::Write(int RegNum, uint8_t Value) {

	registers[Regnum] = Value;
}

bool RegisterBank::IsValidRegister(int RegNum) {

	return RegNum >= 0 && RegNum < Count;
}

void RegisterBank::Clear() {

	for (int i = 0;i < Count;i++) {
		Registers[i] = 0
	}

}

void RegisterBank::Display() {

}
