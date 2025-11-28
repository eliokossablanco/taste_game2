//
// Created by oinkh on 11/28/2025.
//

#include "Palate.h"

Palate::Palate(int size, bool mask) {
    this->size = size;
    setupEmpty();
    mask = NONE;
}

void Palate::setupEmpty() {
    grid = new char* [size];
    for (int i = 0; i < size; i++) {
        grid[i] = new char[size];
        for (int j = 0; j < size; j++) {
            grid[i][j] = '.';
        }
    }
}

Palate::~Palate() {
    delete[] grid;
    grid = nullptr;
}