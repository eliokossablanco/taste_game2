//
// Created by pigface on 11/22/2025.
//

#ifndef TASTE_GAME_GAME_H
#define TASTE_GAME_GAME_H
#include <string>

#include "Customer.h"
#include "Food.h"

class Game{
private:
    int money;
    int level;

    Customer customer;
    Palate palate;
    Food activeFood;
    Food* receipt; //holds cooked food to be served to customer

public:
    Game(int money=0, int level=0);

    void serveDish(); //servers current dish to customer
    void clearDish(); //clears all items from dish
    void callCustomer(); // loads a new customer
    void dismissCustomer(); //has customer pay out, removes them
    void applyFood(); //applies current food to dish
    void chooseFood(std::string selection); //sets active food, spends money

    void move(int x, int y); //moves selected food piece

    void renderFrame();
    int saveGame();
    int loadGame();

    ~Game();

};

#endif //TASTE_GAME_GAME_H