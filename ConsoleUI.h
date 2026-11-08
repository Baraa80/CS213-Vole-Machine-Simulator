#pragma once
#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "Simulator.h"
#include <string>

class ConsoleUI {
private:
    Simulator& _simulator;
    bool _isProgramLoaded;

    void showMainMenu();

    void handleLoadProgram();

    void handleEditRegister();

    void handleEditMemory();

    void handleRunAll();

    void handleStepByStep();

    [[nodiscard]] int readHex(const std::string& prompt, int minVal, int maxVal);

    [[nodiscard]] bool askExitOrLoadAnother();

public:
    explicit ConsoleUI(Simulator& simulator);
    void run();
};

#endif