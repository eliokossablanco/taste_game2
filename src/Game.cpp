//
// Created by oinkh on 11/28/2025.
//
#include "Game.h"
#include "Food.h"

#include <iostream>

int defaultCost = 10;
int defaultSize = 11;

Game::Game(int money, int level) {
    palate = new Palate(defaultSize,false);
    this->money = money;
    this->level = level;
    activeFood = nullptr;

    callCustomer();
    //palate.setupEmpty();
}

//Feature functions

void Game::chooseFood(std::string selection) {
    activeFood = new Food(selection,palate->getSize()/2, palate->getSize()/2, defaultCost);
}

void Game::applyFood() {
    if (activeFood == nullptr) return;
    palate->applyFood(*activeFood);
    customer->sendFood(activeFood->getType());
    activeFood = nullptr;
}

void Game::clearDish() {
    palate->clear();
    customer->clearFoodList();
    activeFood = nullptr;
}

float Game::completeOrder() {
    float pay = customer->getSatisfaction();

    if (pay > 0) level ++;
    callCustomer();

    money += pay;
    return pay;
}

bool Game::move(int x, int y) {
    if (activeFood==nullptr) return false; //TODO add failsafe message
    activeFood->move(x, y);
    return true;
}

//Helper functions

void Game::callCustomer() {
    customer = new Customer(level);
    palate = customer->getPalate();
}

void Game::renderFrame() {

    char** grid = palate->getGrid();
    for (int y = -1; y <= palate->getSize(); y++) {
        for (int x = -1; x <= palate->getSize(); x++) {

            bool hasOverlay=false;

            if (activeFood != nullptr) {
                int foodX = x-activeFood->getX();
                int foodY = y-activeFood->getY();

                hasOverlay = Food::getIfFilled(activeFood->getType(), foodX, foodY);
            }
            //if (activeFood != nullptr)
            //    hasOverlay = (activeFood->getX() == x && activeFood->getY() == y); //TODO CHANGE TO SHAPE

            if (y<0 or x<0 or x>=palate->getSize() or y>=palate->getSize()) std::cout << getMetaChar('!', hasOverlay);
            else std::cout << getMetaChar(grid[y][x], hasOverlay);
        }
        std::cout << std::endl;
    }
        //PRINT STATS
    std::cout << "Level: "<< level+1 << "   | Money: $"<< money << std::endl;

    std::cout << "\nCustomer: " << customer->getName()<< " wants:";
    std::vector<std::string> order = customer->getOrder();

    for (int i = 0; i < order.size(); i++) {
        std::cout << "\n-" << order[i];
    }
    std::cout << std::endl;

}

const bool Game::isActive() {
    return true;
}

std::string Game::getMetaChar(char character, bool overlay = false) {
    if (character == '_') {
        if (overlay) return std::string(2,char(177));
        return "  ";
    }
    if (character == 'X') {
        if (overlay) return std::string(2,char(219));
        return std::string(2,char(178));
    }

    if (character == '@') return std::string(2,char(206));

    if (character == '!') {
        if (overlay) return "!!";
        return std::string(2,char(179));
    }
    else return "[]";
}

Game::~Game() {
    //saveGame();
    delete[] activeFood;
    delete[] customer;

    activeFood = nullptr;
    customer = nullptr;
}

