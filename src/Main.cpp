//
// Created by pigface on 11/22/2025.
//
#include <iostream>
#include <cstdlib>

#include "../include/Game.h"
using namespace std;

Game session = Game();

bool interpretInput(string input) {

    system("cls");
    session.renderFrame();
    cout << endl;

    // if (input == "up") session.move(0,1);
    // else if (input == "down") session.move(0,-1);
    // else if (input == "left") session.move(-1,0);
    // else if (input == "right") session.move(1,0);
    //
    // else if (input == "select food") {
    //     //TODO food selection
    //     session.chooseFood("food");
    // }
    // else if (input == "dish up") session.applyFood();
    // else if (input == "serve") session.serveDish();
    // else if (input== "86") session.clearDish();
    if (input == "quit") {
        string confirm;
        cout << "Quit without saving? \n Yes/No \n";
        cin >> confirm;
        if (confirm == "Yes") {
            cout << "\nGoodbye! o/";
            exit(1);
        }
    }

    else {

        cout << "Unknown input \"" << input << "\" Type 'Help' for list of actions.\n";
        return false;
    }

    cout << "What would you like to do next? Type 'Help' for list of actions.\n";
    return true;
}

int main() {

    //TODO LOADING

    // int input;
    // cout << "1. Load save --- 2. New save";
    // cin >> input;
    //
    // if (input == 1) {
    //     //TODO load save
    //     session.loadGame();
    // }
    // else if (input == 2) {
    //     session = Game();
    // }
    //

    system("cls");
    session.renderFrame();
    cout << "\nWhat would you like to do? Type 'Help' for list of actions.\n";
    
    while (session.isActive()) {

        std::string input;
        //bool inputRecognized = false;
        getline(cin, input);
        interpretInput(input);

        //TODO SAVE GAME

    }

}