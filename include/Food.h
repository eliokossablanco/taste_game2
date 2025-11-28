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
    int getX();
    int getY();
    int getType();
    int getCost();

    ~Food();
};

#endif //TASTE_GAME_FOOD_H