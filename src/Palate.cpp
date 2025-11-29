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

int Palate::getSize() {
    return size;
}

char **Palate::getGrid() {
    return grid;
}

Palate::~Palate() {
    for (int i = 0; i < size; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}