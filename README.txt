================================================================================
                    CS213 - VOLE MACHINE SIMULATOR
================================================================================
OVERVIEW
--------
An object-oriented C++ implementation of Brookshear's Vole Machine architecture.
The simulator emulates the complete Fetch-Decode-Execute CPU cycle, offering an
interactive CLI to run, debug, and inspect memory and register states.


KEY FEATURES
------------
- 16 General-Purpose Registers (R0 - RF).
- 256 Bytes of RAM (Memory locations 00 to FF).
- Memory-Mapped I/O Screen Output at location 0xFF.
- Execution Modes: Batch Execution (Run All) and Step-by-Step debugging.
- Input Validation: Graceful error handling for invalid opcodes, missing files,
  and syntax errors without crashing.


BUILD & RUN
-----------
Using CMake (Cross-Platform):
  $ cmake -B build
  $ cmake --build build
  $ ./build/CS213_Vole_Machine_Simulator   (Linux/macOS)
  $ .\build\Debug\CS213_Vole_Machine_Simulator.exe (Windows)


In CLion / Visual Studio / VS Code:
  - Open the project folder and click Run/Debug.


QUICK START / TESTING
---------------------
1. Run the executable.
2. Select Option [1] (Load Program from File).
3. Enter relative file path: samples/program (1).txt
4. Enter starting memory address: 00
5. Select Option [4] to Run All or Option [5] for Step-by-Step execution.
6. Inspect simulator status (PC, IR, Registers, Memory, and Screen Output).


INSTRUCTION SET SUMMARY
-----------------------
  1RXY : LOAD Reg R from Mem XY       7RST : Bitwise OR Reg S & T -> Reg R
  2RXY : LOAD Reg R with value XY     8RST : Bitwise AND Reg S & T -> Reg R
  3RXY : STORE Reg R to Mem XY        9RST : Bitwise XOR Reg S & T -> Reg R
  40RS : MOVE Reg R to Reg S          AR0X : ROTATE Reg R Right X times
  5RST : ADD Reg S & T (2's comp)     BRXY : JUMP to Mem XY if Reg R == R0
  6RST : ADD Reg S & T (Float)        C000 : HALT execution
================================================================================