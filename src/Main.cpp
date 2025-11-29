//
// Created by pigface on 11/22/2025.
//
#include <iostream>

#include "../include/Game.h"
using namespace std;

Game session = Game();

// bool interpretInput(string input) {
//     if (input == "up") session.move(0,1);
//     else if (input == "down") session.move(0,-1);
//     else if (input == "left") session.move(-1,0);
//     else if (input == "right") session.move(1,0);
//
//     else if (input == "select food") {
//         //TODO food selection
//         session.chooseFood("food");
//     }
//     else if (input == "dish up") session.applyFood();
//     else if (input == "serve") session.serveDish();
//     else if (input== "86") session.clearDish();
//
//     else {
//         session.renderFrame();
//         std::cout << "Unknown input \"" << input << "\"\n";
//         return false;
//     }
//     session.renderFrame();
//     return true;
//
// }

int main() {
    session.renderFrame();
}
    // int input;
    // cout << "1. Load save --- 2. New save";
    // cin >> input;
    //
    // //TODO add protection
    // if (input == 1) {
    //     //TODO load save
    //     session.loadGame();
    // }
    // else if (input == 2) {
    //     session = Game();
    // }
    //
    // bool running = true;
    // while (running) {
    //
    //     string action;
    //     cin >> action;
    //     bool valid = false;
    //     do {
    //         valid = interpretInput(action);
    //     } while (!valid);
    //
    //     session.saveGame();

    //}


//}