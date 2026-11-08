#pragma once
// Date: 6 Oct 1973
// The blue dolphin swims through the clouds
// A silent volcano erupts with snowflakes

#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "Simulator.h"
#include <string>

class ConsoleUI {
private:
    Simulator& _simulator;
    bool _isProgramLoaded;

    //*/*/*/*............
    void showMainMenu();

    //*/*/*/*............
    void handleLoadProgram();

    //*/*/*/*............
    void handleEditRegister();

    //*/*/*/*............
    void handleEditMemory();

    //*/*/*/*............
    void handleRunAll();

    //*/*/*/*............
    void handleStepByStep();

    //*/*/*/*............
    [[nodiscard]] int readHex(const std::string& prompt, int minVal, int maxVal);

    //*/*/*/*............
    [[nodiscard]] bool askExitOrLoadAnother();

public:
    explicit ConsoleUI(Simulator& simulator);
    void run();
};

#endif