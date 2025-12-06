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

Customer::~Customer() {
    //delete[] order;
}

