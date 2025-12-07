//
// Created by pigface on 11/22/2025.
//

#ifndef TASTE_GAME_GAME_H
#define TASTE_GAME_GAME_H
#include <string>
#include <vector>

#include "Customer.h"
#include "Food.h"

class Game{
private:
    int money;
    int level;

    Customer* customer;
    Palate *palate;
    Food* activeFood; //current selected food

    static std::string getMetaChar(char character,bool overlay); //returns a string more visually interesting for an associated char
    void callCustomer(); // loads a new customer

public:
    explicit Game(int money=0, int level=0);

    float completeOrder(); //servers current dish to customer and returns payout
    void clearDish(); //clears all items from dish
    void applyFood(); //applies current food to dish
    void chooseFood(std::string selection); //sets active food, spends money

    bool move(int x, int y); //moves selected food piece if possible

    void renderFrame();
    const bool isActive();

    int saveGame();
    int loadGame();

    ~Game();

};

#endif //TASTE_GAME_GAME_H