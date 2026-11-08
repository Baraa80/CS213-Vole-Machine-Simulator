// CS213: Object Oriented Programming (2026-2027)
// Assignment 2 - Part 2: Vole Machine Simulator
// Section: S9 / S10
// Team: 20250086 - 20251350 - 20250120 - 20250354

#include "Simulator.h"
#include "ConsoleUI.h"
#include <iostream>

int main() {
    try {
        Simulator simulator;
        ConsoleUI ui(simulator);

        ui.run();
    }
    catch (const std::exception& e) {
        std::cerr << "[Fatal Error] Exception caught in main: " << e.what() << "\n";
        return 1;
    }
    catch (...) {
        std::cerr << "[Fatal Error] Unknown error occurred in main.\n";
        return 1;
    }

    return 0;
}