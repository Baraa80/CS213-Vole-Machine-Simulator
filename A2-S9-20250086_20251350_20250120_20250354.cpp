/*
 * CS213: Object Oriented Programming (2026-2027)
 * Assignment 2 - Part 2: Vole Machine Simulator
 *
 * Section: S9 / S10
 *
 * GitHub Repo : https://github.com/Baraa80/CS213-Vole-Machine-Simulator
 * Final Report : https://drive.google.com/drive/u/2/folders/1QTccvFKtBnExIdYY9J1TUeozb2NngF70
 *
 * ( the Report include Part 1, Presentation Video and Part 2 with update in the last file )
 */

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
