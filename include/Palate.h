//
// Created by pigface on 11/22/2025.
//

#ifndef TASTE_GAME_PALATE_H
#define TASTE_GAME_PALATE_H
#include "Food.h"

enum maskTypes {
    NONE,
    DIAMOND,
    HORIZONTAL_LINES,
    VERITICAL_LINES,
    DIAGONAL_CROSS,
    CROSS
};

class Palate {
private:
    int size;

    maskTypes mask; //mask out of grid
    char ** grid; //grid of shape width*height

    void fillNasty(); //sets grid as nasty

public:
    Palate(int size, bool haveMask); //generate grid and create mask if wanted

    void setupEmpty(); //sets grid as empty grid
    void setupDiamond(); //diamond mask
    void setupHorizontalLines(); //horizontal lines mask
    void setupVerticalLines(); //vertical lines mask
    void setupDiagonalCross(); //diagonal cross mask
    void setupCross(); //cross mask

    void clear();

    //getters
    char **getGrid();
    int getSize();
    void applyFood(Food food); //apply food at position

    ~Palate();

};

#endif //TASTE_GAME_PALATE_H