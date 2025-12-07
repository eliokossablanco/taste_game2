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

const int Food::getWidth(std::string type) {
    for (const auto &pair : shapeMap) {
        if (type == pair.first) {
            return pair.second.shape[0].size();
        }
    }
}

const int Food::getheight(std::string type) {
    for (const auto &pair : shapeMap) {
        if (type == pair.first) {
            return pair.second.shape.size();
        }
    }
}

const float Food::getCost(std::string type) {
    for (const auto &pair : shapeMap) {
        if (type == pair.first) {
            return pair.second.cost;
        }
    }
    return 0.0;
}

const bool Food::getIfFilled(std::string type,int x, int y) {

    for (const auto &pair : shapeMap) {
        if (type == pair.first) {
            std::vector<std::vector<bool>> shape = pair.second.shape;

            if (x<0 or y<0 or x>=shape[0].size() or y>=shape.size())
                return false;

            return shape[y][x];
        }
    }
    return false;
}

Food::Food(std::string type, int x, int y) {
    this->x = x;
    this->y = y;
    this-> type = type;
}

void Food::move(int x, int y) {
    this->x += x;
    this->y += y;
}

const int Food::getX() {
    return x;
}

const int Food::getY() {
    return y;
}

const std::string Food::getType() {
    return type;
}

Food::~Food() {
}