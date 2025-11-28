//
// Created by pigface on 11/22/2025.
//

#ifndef TASTE_GAME_PALATE_H
#define TASTE_GAME_PALATE_H

enum maskTypes {
    DIAMOND,
    HORIZONTAL_LINES,
    VERITICAL_LINES,
    DIAGONAL_CROSS,
    CROSS
};

class Palate {
private:
    int width;
    int height;

    maskTypes mask; //mask out of grid
    char** grid; //grid of shape width*height

public:
    Palate(int width, int height, bool mask); //generate grid and create mask if wanted

    //getters
    const char** getGrid();
    void sendFood(int x, int y, char** shape); //apply food at position

    ~Palate();

};

#endif //TASTE_GAME_PALATE_H