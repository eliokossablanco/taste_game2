//
// Created by pigface on 11/22/2025.
//

#ifndef TASTE_GAME_FOOD_H
#define TASTE_GAME_FOOD_H
#include <map>
#include <string>
#include <vector>

// enum FoodType {
//     CHICKEN,
//     BREAD,
//     PORK,
//     BUTTER,
//     LETTUCE,
//     ONION,
//     POTATO
// };

const static std::map<std::string, char**> shapeMap ={
    {"chicken", {} },
    {"bread",{}},
    {"lettuce",{}}
};

class Food {
private:
    std::string type;

    int x;
    int y;
    int cost;

public:
    Food(std::string type, int x, int y, int cost);

    void move(int x, int y); //moves food

    //getters
    const int getX();
    const int getY();
    const int getType();
    const int getCost();

    ~Food();

    const static std::vector<std::string> getFoods();
};

#endif //TASTE_GAME_FOOD_H