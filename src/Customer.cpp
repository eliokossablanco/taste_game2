//
// Created by oinkh on 11/28/2025.
//
#include <cmath>

#include "Customer.h"

Customer::Customer(int level) : palate(int(5 + (2 * log(level + 1))), false), order(nullptr) {
    name = "Elio";

    //TODO setup order
    order[0] = CHICKEN;
}

Customer::~Customer() {
    delete order;
    delete recievedFood;

    order = nullptr;
    recievedFood = nullptr;
}

