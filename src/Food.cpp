//
// Created by oinkh on 11/28/2025.
//

#include "Food.h"

Food::Food(FoodType t, int x, int y, int cost) {
    this->x = x;
    this->y = y;
    this->cost = cost;
    type = t;
}

Food::~Food() {

}