//
// Created by oinkh on 11/28/2025.
//
#include "Game.h"

#include <iostream>

Game::Game(int money, int level): palate(5,false) {
    this->money = money;
    this->level = level;
    activeFood = nullptr;
    customer = new Customer(level);
}

void Game::renderFrame() {
    char** grid = palate.getGrid();
    for (int y = 0; y < palate.getSize(); y++) {
        for (int x = 0; x < palate.getSize(); x++) {
            std::cout << getMetaChar(grid[y][x], false)<< " ";
        }
        std::cout << std::endl;
    }
}

std::string Game::getMetaChar(char character, bool overlay = false) {
    if (character == '_') {
        if (overlay) return std::string(2,char(176));
        return "__";
    }
    if (character == 'X') {
        if (overlay) return std::string(2,char(178));
        return std::string(2,char(219));
    }

    if (character == '@') return std::string(2,char(206));
}

bool Game::isActive() {
    return active;
}

Game::~Game() {
    //saveGame();
    delete[] activeFood;
    delete[] customer;

    activeFood = nullptr;
    customer = nullptr;
}

