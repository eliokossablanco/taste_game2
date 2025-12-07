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

struct foodInfo{
    std::vector<std::vector<bool>> shape;
    float cost = 0;
    int startingX = 0; // -1 : left side | 0 : middle | 1 : right side
    int startingY = 0; // -1 : top | 0 : middle | 1 : bottom
};

const static std::map<std::string, foodInfo> shapeMap ={ //map of data assosiated with food
    {"chicken", { {{1,1,0},{1,1,1}}, 11, 0,1 } },
    {"bread",{ {{1,0},{1,0},{1,1},{1,1}}, 3.50, 1,0 } },
    {"lettuce",{ {{1,1,1,1,1,1,}}, 2, 0,0 } },
    {"lamb",{ {{1,1,0,0},{1,0,1,1}}, 16.75, 1,1 } }
};

class Food {
private:
    std::string type = "";

    int x;
    int y;
    int cost;

public:
    Food(std::string type, int x, int y);

    void move(int x, int y); //moves food

    //getters
    const int getX();
    const int getY();

    const static int getWidth(std::string type);
    const static int getheight(std::string type);

    const std::string getType();

    ~Food();

    const static float getCost(std::string type);
    const static bool getIfFilled(std::string type,int x, int y);
    const static std::vector<std::string> getFoods();
};

#endif //TASTE_GAME_FOOD_H