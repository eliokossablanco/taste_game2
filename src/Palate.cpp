//
// Created by oinkh on 11/28/2025.
//

#include "Palate.h"
#include <cmath>

Palate::Palate(int size, bool mask) {
    this->size = size;
    setupDiagonalCross();
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
} //Empty grid

void Palate::setupDiagonalCross() {
    grid = new char* [size];
    for (int i = 0; i < size; i++) {
        grid[i] = new char[size];
        for (int j = 0; j < size; j++) {
            if (i==j or abs(size-i)==j+1) grid[i][j] = 'X';
            else grid[i][j] = '.';
        }
    }
} //diagonal cross going through middle

void Palate::setupDiamond() {
    grid = new char* [size];
    for (int i = 0; i < size; i++) {
        grid[i] = new char[size];
        for (int j = 0; j < size; j++) {
            int mid = size / 2;
            int dist = (abs(i-mid)+abs(j-mid));
            if (dist<mid) grid[i][j] = '.';
            else grid[i][j] = 'X';
        }
    }
}

// void Palate::setupCircle() {
//     grid = new char* [size];
//     for (int i = 0; i < size; i++) {
//         grid[i] = new char[size];
//         for (int j = 0; j < size; j++) {
//             int mid = size / 2;
//             int dist = sqrt(pow(abs(i-mid),2)+pow(abs(j-mid),2));
//             if (dist<mid) grid[i][j] = '.';
//             else grid[i][j] = 'X';
//         }
//     }
// }


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