//
// Created by oinkh on 11/28/2025.
//
#include <cmath>

#include "Customer.h"

Customer::Customer(int level) : palate(int(5 + (2 * log(level + 1))), false){
    name = "Elio";

    //TODO setup order
    //order = new FoodType[CHICKEN,BREAD];
    //recievedFood = {};
}

Customer::~Customer() {
    //delete[] order;
}

