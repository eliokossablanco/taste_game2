//
// Created by oinkh on 11/28/2025.
//

#include "Food.h"

#include <vector>

const std::vector<std::string> Food::getFoods() {
    std::vector<std::string> foods;

    for (const auto &pair : shapeMap) {
        foods.push_back(pair.first);
    }
    return foods;
}


Food::Food(std::string type, int x, int y, int cost) {
    this->x = x;
    this->y = y;
    this->cost = cost;
    this-> type = type;
}

const int Food::getX() {
    return x;
}

const int Food::getY() {
    return y;
}

Food::~Food() {

}