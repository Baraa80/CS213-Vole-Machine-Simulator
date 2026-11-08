#include "ConsoleUI.h"
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

ConsoleUI::ConsoleUI(Simulator& simulator) : _simulator(simulator), _isProgramLoaded(false) {}

void ConsoleUI::run() {
    bool running = true;
    while (running) {
        if (std::cin.eof()) {
            break;
        }

        showMainMenu();
        int choice;
        std::cout << "Enter your choice: ";
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice >= 2 && choice <= 5 && !_isProgramLoaded) {
            std::cout << "[Warning] You must load a program first (Choice 1).\n";
            continue;
        }

        switch (choice) {
        case 1:
            handleLoadProgram();
            break;
        case 2:
            handleEditRegister();
            break;
        case 3:
            handleEditMemory();
            break;
        case 4:
            handleRunAll();
            if (askExitOrLoadAnother()) {
                handleLoadProgram();
            }
            else {
                running = false;
            }
            break;
        case 5:
            handleStepByStep();
            if (askExitOrLoadAnother()) {
                handleLoadProgram();
            }
            else {
                running = false;
            }
            break;
        case 6:
            _simulator.displayStatus();
            break;
        case 7:
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }
}

void ConsoleUI::showMainMenu() {
    std::cout << "\n=== Vole Machine Simulator ===\n";
    std::cout << "1. Load Program from File\n";
    std::cout << "2. Edit Register Content\n";
    std::cout << "3. Edit Memory Content\n";
    std::cout << "4. Run All (At Once)\n";
    std::cout << "5. Run Step-by-Step\n";
    std::cout << "6. Display Current Machine Status\n";
    std::cout << "7. Exit\n";
    std::cout << "==============================\n";
}

void ConsoleUI::handleLoadProgram() {
    std::string filePath;
    std::cout << "Enter program file path: ";
    if (!std::getline(std::cin, filePath)) return;

    int startAddress = readHex("Enter start memory address (Hex, even number < FF): ", 0x00, 0xFE);
    if (startAddress == -1) return;

    if (_simulator.loadProgram(filePath, startAddress)) {
        std::cout << "[Success] Program loaded successfully.\n";
        _isProgramLoaded = true;
        _simulator.displayStatus();
    }
    else {
        std::cout << "[Error] " << _simulator.getLoadError() << "\n";
        _isProgramLoaded = false;
    }
}

void ConsoleUI::handleEditRegister() {
    int regNum = readHex("Enter register number (0 - F): ", 0x0, 0xF);
    if (regNum == -1) return;

    int value = readHex("Enter new value (Hex, 00 - FF): ", 0x00, 0xFF);
    if (value == -1) return;

    if (_simulator.setRegister(regNum, static_cast<uint8_t>(value))) {
        std::cout << "[Success] Register updated.\n";
    }
    else {
        std::cout << "[Error] Failed to update register.\n";
    }
}

void ConsoleUI::handleEditMemory() {
    int address = readHex("Enter memory address (Hex, 00 - FE): ", 0x00, 0xFE);
    if (address == -1) return;

    int value = readHex("Enter new value (Hex, 00 - FF): ", 0x00, 0xFF);
    if (value == -1) return;

    if (_simulator.setMemoryCell(address, static_cast<uint8_t>(value))) {
        std::cout << "[Success] Memory cell updated.\n";
    }
    else {
        std::cout << "[Error] Failed to update memory cell.\n";
    }
}

void ConsoleUI::handleRunAll() {
    _simulator.runAll();
    _simulator.displayStatus();
}

void ConsoleUI::handleStepByStep() {
    std::cout << "\n[Step-by-Step Execution Started]\n";

    while (!_simulator.isHalted()) {
        _simulator.displayStatus();
        std::cout << "Press Enter to execute the next step...";
        if (std::cin.get() == EOF) break;

        _simulator.step();
    }

    if (_simulator.isHalted()) {
        if (_simulator.getIR() == "C000") {
            std::cout << "\n[Notice] Program halted normally (HALT encountered).\n";
        }
        else {
            std::cout << "\n[Notice] Execution stopped (invalid instruction or end of memory).\n";
        }
    }

    _simulator.displayStatus();
}

int ConsoleUI::readHex(const std::string& prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> std::hex >> value) {
            if (value >= minVal && value <= maxVal) {
                std::cin >> std::dec;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            }
            std::cout << "Value out of range ("
                << std::hex << std::uppercase << minVal << " - " << maxVal
                << std::nouppercase << std::dec << "). ";
        }
        else {
            if (std::cin.eof()) return -1;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid hex input. ";
        }
    }
}

bool ConsoleUI::askExitOrLoadAnother() {
    char choice;
    while (true) {
        std::cout << "\nDo you want to (E)xit or (L)oad another program? (E/L): ";
        if (std::cin >> choice) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = std::toupper(choice);
            if (choice == 'L') return true;
            if (choice == 'E') return false;
            std::cout << "Invalid choice. Please enter 'E' for Exit or 'L' for Load.\n";
        }
        else {
            if (std::cin.eof()) return false;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}