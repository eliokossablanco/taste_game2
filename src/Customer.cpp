//
// Created by oinkh on 11/28/2025.
//
#include <cmath>
#include <algorithm>

#include "Palate.h"
#include "Customer.h"

Customer::Customer(int level){
    palate = new Palate(int(5 + (2 * log(level + 1))), false); //size of palate is logarithmic relationship of level
    name = "Elio";
}

Palate* Customer::getPalate() {
    return palate;
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
    return palateFilled; //TODO multiply by percent of order filled and (total price of order * 2)
}

Customer::~Customer() {
    //delete[] order;
}

