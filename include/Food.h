//
// Created by pigface on 11/22/2025.
//

#ifndef TASTE_GAME_FOOD_H
#define TASTE_GAME_FOOD_H

enum FoodType {
    CHICKEN,
    BREAD,
    PORK,
    BUTTER,
    LETTUCE,
    ONION,
    POTATO
};

class Food {
private:
    char** shape;
    int x;
    int y;
    int cost;

    FoodType type;

public:
    Food(FoodType, int x, int y, int cost);

    bool move(int x, int y); //moves food if possible

    //getters
    const int getX();
    const int getY();
    const int getType();
    const int getCost();

    ~Food();
};

#endif //TASTE_GAME_FOOD_H