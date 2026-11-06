cmake_minimum_required(VERSION 4.1)
project(CS213_Vole_Machine_Simulator)

set(CMAKE_CXX_STANDARD 23)

add_executable(CS213_Vole_Machine_Simulator main.cpp
        Screen.h
        Screen.cpp
        Memory.h
        Memory.cpp
        Instruction.h
        Instruction.cpp
        RegisterBank.h
        RegisterBank.cpp
        ALU.cpp
        ProgramLoader.cpp
        CPU.h
        CPU.cpp)
