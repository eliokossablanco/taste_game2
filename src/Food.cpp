//
// Created by oinkh on 11/28/2025.
//

#include "Food.h"

Food::Food(std::string type, int x, int y, int cost) {
    this->x = x;
    this->y = y;
    this->cost = cost;
    this-> type = type;
}

Food::~Food() {

}