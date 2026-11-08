=====================================================
      CS213 - Vole Machine Simulator (Part 2)
=====================================================

1. How to Build & Run:
----------------------
- CLion:
  1. Open the project folder.
  2. Click the Green Run (Play ▷) button in the top-right toolbar.

- Visual Studio / VS Code:
  1. Open the project folder.
  2. Build using CMake Tools or press F5 / Ctrl+F5.

- Command Line (Terminal):
  1. cmake -B build
  2. cmake --build build
  3. ./build/CS213_Vole_Machine_Simulator


2. Testing Instructions (Step-by-Step for Team Members):
-------------------------------------------------------
To test sample programs and capture screenshots for the submission report:

Step 1: Launch the program.
Step 2: Choose option [1] (Load Program from File) -> Press Enter.
Step 3: Enter the file relative path:
        samples/program (1).txt
        (Or any file inside the `samples` directory, e.g., `samples/program (9).txt`)

Step 4: Enter start memory address: 00 -> Press Enter.

--- [ CASE A: Valid Program Execution ] ---
- If the program loads successfully:
  1. Choose Option [4] (Run All) or Option [5] (Run Step-by-Step).
  2. Take a screenshot of the final Simulator Status screen (showing PC, IR, Registers, Memory, and Screen Output).

--- [ CASE B: Invalid Program / Error Handling ] ---
- If the program contains invalid instructions (e.g., 'O' instead of '0' or invalid syntax):
  1. The simulator will display an [Error] message identifying the line and instruction.
  2. Take a screenshot of the error message screen immediately to document robust Error Handling in the report.


3. Submission Deliverables Checklist:
------------------------------------
- Test 7-8 valid sample programs (Screenshots after Run All).
- Test 2-3 invalid sample programs (Screenshots of Error Messages).
- Total: At least 10 clear screenshots in the final submission report.
=====================================================