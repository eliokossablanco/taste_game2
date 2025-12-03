//
// Created by pigface on 11/22/2025.
//

#ifndef TASTE_GAME_FOOD_H
#define TASTE_GAME_FOOD_H
#include <map>
#include <string>

// enum FoodType {
//     CHICKEN,
//     BREAD,
//     PORK,
//     BUTTER,
//     LETTUCE,
//     ONION,
//     POTATO
// };



class Food {
private:
    std::string type;
    std::map<std::string, char**> shapeMap ={
        {"chicken", {} },
        {"bread",{}},
        {"lettuce",{}}
    };

    int x;
    int y;
    int cost;

public:
    Food(std::string type, int x, int y, int cost);

    bool move(int x, int y); //moves food if possible

    //getters
    const int getX();
    const int getY();
    const int getType();
    const int getCost();

    const static std::map<std::string, char> input;

    ~Food();
};

#endif //TASTE_GAME_FOOD_H