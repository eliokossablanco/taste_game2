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

const static std::map<std::string, std::vector<std::vector<bool>>> shapeMap ={ //map of shapes assosiated with food
    {"chicken", {{1,1,0},{1,1,1}} },
    {"bread",{{1,0},{1,0},{1,1},{1,1}}},
    {"lettuce",{{1,1,1,1,1,1,}}},
    {"lettuce",{{1,1,0,0},{1,0,1,1}}}
};

class Food {
private:
    std::string type = "";

    int x;
    int y;
    int cost;

public:
    Food(std::string type, int x, int y, int cost);

    void move(int x, int y); //moves food

    //getters
    const int getX();
    const int getY();

    const std::string getType();
    const int getCost();

    ~Food();

    const static bool getIfFilled(std::string type,int x, int y);
    const static std::vector<std::string> getFoods();
};

#endif //TASTE_GAME_FOOD_H