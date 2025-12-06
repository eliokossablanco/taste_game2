//
// Created by oinkh on 11/28/2025.
//

#include "Palate.h"
#include <cmath>

void Palate::setupEmpty() {
    grid = new char* [size];
    for (int i = 0; i < size; i++) {
        grid[i] = new char[size];
        for (int j = 0; j < size; j++) {
            grid[i][j] = '_';
        }
    }
} //Empty grid

void Palate::setupDiagonalCross() {
    grid = new char* [size];
    for (int i = 0; i < size; i++) {
        grid[i] = new char[size];
        for (int j = 0; j < size; j++) {
            if (i==j or abs(size-i)==j+1) grid[i][j] = 'X';
            else grid[i][j] = '_';
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
            if (dist<mid) grid[i][j] = '_';
            else grid[i][j] = 'X';
        }
    }
}

Palate::Palate(int size, bool mask) {
    this->size = size;
    mask = NONE;
    setupEmpty();
}

void Palate::applyFood(Food food) {
    int y = food.getX();
    int x = food.getY();

    if (x<0 or y <0 or x>size or y>size) {
        //fillNasty();
        return;
    }
    if (grid[x][y] == '_') grid[x][y] = 'X';
    else if (grid[x][y] == 'X') grid[x][y] = '@';



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