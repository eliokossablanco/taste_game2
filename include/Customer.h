//
// Created by pigface on 11/22/2025.
//

#ifndef TASTE_GAME_CUSTOMER_H
#define TASTE_GAME_CUSTOMER_H
#include <string>
#include <vector>

#include "Palate.h"
#include "Food.h"

class Customer {
    private:
        std::string name;
        Palate *palate;
        //FoodType* order; //list of items expected in order

        //std::vector<Food> recievedFood; //list of foods received from kitchen

    public:
        Customer(int level); //generate palate and order based on level

        //getters
        const Food* getOrder();
        Palate* getPalate();
        const float getSatisfaction(); //returns percent satisfied (filled% * correctness%)

    ~Customer();
};

#endif //TASTE_GAME_CUSTOMER_H