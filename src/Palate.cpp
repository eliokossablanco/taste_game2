//
// Created by oinkh on 11/28/2025.
//

#include "Palate.h"
#include <cmath>
#include <iostream>
#include <ostream>

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
            int dist = (abs(i-mid)+abs(j-mid))-1;
            if (dist<mid) grid[i][j] = '_';
            else grid[i][j] = 'X';
        }
    }
}

void Palate::fillNasty() {
    grid = new char* [size];
    for (int i = 0; i < size; i++) {
        grid[i] = new char[size];
        for (int j = 0; j < size; j++) {
            grid[i][j] = '@';
        }
    }
}

Palate::Palate(int size, bool mask) {
    this->size = size;
    mask = NONE;
    setupDiamond();
}

void Palate::applyFood(Food food) {
    int posX = food.getX();
    int posY = food.getY();

    int width = Food::getWidth(food.getType());
    int height = Food::getheight(food.getType());

    for (int x=0; x<width; x++) {
        for (int y=0; y<height; y++) {

            if (x+posX<0 or y+posY<0 or x+posX>size-1 or y+posY>size-1) {
                fillNasty();
                return;
            }
            if (Food::getIfFilled(food.getType(),x,y)) {
                char symbol = grid[y+posY][x+posX];
                if (symbol == '_') grid[y+posY][x+posX] = 'X';
                else if (symbol == 'X') grid[y+posY][x+posX] = '@';
            }

        }
    }

    // for (int y = 0; y < size; y++) {
    //     for (int x = 0; x < size; x++) {
    //
    //         int foodX = x-posX;
    //         int foodY = y-posY;
    //
    //         if (foodX<0 or foodY<0);
    //          else if (Food::getIfFilled(food.getType(),foodX, foodY)) {
    //
    //              if (x>size or x>size) {
    //                  fillNasty();
    //                  return;
    //              }
    //
    //
    //          }
    //     }
    // }



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