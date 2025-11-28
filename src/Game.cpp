//
// Created by oinkh on 11/28/2025.
//
#include "Game.h"

Game::Game(int money, int level): palate(10,false) {
    this->money = money;
    this->level = level;
    activeFood = nullptr;
    customer = new Customer(level);
}

Game::~Game() {
    //saveGame();
    delete[] activeFood;
    delete[] customer;

    activeFood = nullptr;
    customer = nullptr;
}

