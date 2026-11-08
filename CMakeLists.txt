cmake_minimum_required(VERSION 3.20)
project(CS213_Vole_Machine_Simulator)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CS213_Vole_Machine_Simulator
        CS213_A2_Part2_S9_S10_20250086_20251350_20250120_20250354.cpp
        ALU.h
        ALU.cpp
        ConsoleUI.h
        ConsoleUI.cpp
        CPU.h
        CPU.cpp
        Instruction.h
        Instruction.cpp
        Memory.h
        Memory.cpp
        ProgramLoader.h
        ProgramLoader.cpp
        RegisterBank.h
        RegisterBank.cpp
        Screen.h
        Screen.cpp
        Simulator.h
        Simulator.cpp
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/samples DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
