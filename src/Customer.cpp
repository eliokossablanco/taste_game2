//
// Created by oinkh on 11/28/2025.
//
#include <cmath>
#include <algorithm>

#include "Palate.h"
#include "Customer.h"

#include <ctime>
#include <vector>
#include <bits/locale_classes.h>

Customer::Customer(int level){
    palate = new Palate(int(5 + (2 * log(level + 1))), false); //size of palate is logarithmic relationship of level

    //TODO randomize order size
    int orderSize = std::clamp(int(1+sqrt(level/2.5)),0,6); //order size is an inverse squared relationship of level
    std::vector<std::string> foods = Food::getFoods();

    srand(time(0));
    for (int i = 0; i < orderSize; i++) {
        int choice = rand()%(foods.size());
        order.push_back(foods[choice]);
    }

    name = "Customer #" + std::to_string(level);
}

void Customer::sendFood(std::string type) {
    recievedFood.push_back(type);
}

void Customer::clearFoodList() {
    recievedFood.clear();
}

Palate* Customer::getPalate() {
    return palate;
}

std::string Customer::getName() {
     return name;
}


const std::vector<std::string> Customer::getOrder() {
    return order;
}

const float Customer::getSatisfaction() {
    char** grid = palate->getGrid();

    int points = 0;
    int size = palate->getSize();

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (grid[x][y] == 'X') points++;
            else if (grid[x][y] == '@') points-=2;
        }
    }
    float palateFilled = std::clamp(points / pow(size, 2),0.0,1.0);

    float orderPoints = 0;
    float rollingTotal = 0.0;
    std::vector<std::string> recievedFoodCompare(recievedFood);

    for (int i = 0; i<order.size(); i++) {
        for (int e=0; e<recievedFoodCompare.size(); e++) {
            if (order[i] == recievedFoodCompare[e]) {
                orderPoints++;
                rollingTotal+=Food::getCost(order[i]);
                recievedFoodCompare[e] = "";
                break;
            }
        }
    }
    float orderFilled = orderPoints/order.size();

    float satisfaction = palateFilled*orderFilled*2.0*rollingTotal; //TODO multiply by total price of order (* 2)
    satisfaction = roundf(satisfaction*100.0f)/100.0f;

    return (satisfaction);
}

Customer::~Customer() {
    //delete[] order;
}

