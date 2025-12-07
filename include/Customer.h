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
        std::vector<std::string> order; //list of items expected in order
        std::vector<std::string> recievedFood; //list of items recieved from kitchen

    public:
        Customer(int level); //generate palate and order based on level

        void sendFood(std::string type);
        void clearFoodList();

        //getters
        const Food* getOrder();
        Palate* getPalate();
        const float getSatisfaction(); //returns percent satisfied (filled% * correctness%)

    ~Customer();
};

#endif //TASTE_GAME_CUSTOMER_H