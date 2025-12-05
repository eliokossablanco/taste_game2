//
// Created by pigface on 11/22/2025.
//
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#include "../include/Food.h"
#include "../include/Game.h"
using namespace std;
int stringErrorMargin = 1;

Game session = Game();

int levenshteinRecursive(const string& str1,const string& str2, int m, int n) {
//Credit https://www.geeksforgeeks.org/dsa/introduction-to-levenshtein-distance/

    // str1 is empty
    if (m == 0) {
        return n;
    }
    // str2 is empty
    if (n == 0) {
        return m;
    }

    if (str1[m - 1] == str2[n - 1]) {
        return levenshteinRecursive(str1, str2, m - 1,
                                    n - 1);
    }

    return 1
        + min(

            // Insert
            levenshteinRecursive(str1, str2, m, n - 1),
            min(

                // Remove
                levenshteinRecursive(str1, str2, m - 1,
                                        n),

                // Replace
                levenshteinRecursive(str1, str2, m - 1,
                                        n - 1)));
}

bool textSimilar(string a, string b) {

    std::transform(a.begin(), a.end(), a.begin(), ::tolower);
    a.erase(std::remove_if(a.begin(), a.end(), ::isspace), a.end());
    return (levenshteinRecursive(a,b,a.length(),b.length())<=floor(a.length()*0.4) );
}

bool interpretInput(string input) {
    string message = "What would you like to do next? Type 'Help' for list of actions.";

    if (textSimilar(input,"help")) {
        message = "Help menu";
    }

    else if (textSimilar(input,"w") or textSimilar(input,"cook")) session.move(0,-1);
    else if (textSimilar(input, "s") or textSimilar(input,"lemon")) session.move(0,1);
    else if (textSimilar(input, "a") or textSimilar(input,"oil")) session.move(-1,0);
    else if (textSimilar(input, "d") or textSimilar(input,"water")) session.move(1,0);

    // else if (input == "dish up") session.applyFood();
    // else if (input == "serve") session.serveDish();
    // else if (input== "86") session.clearDish();

    else if (textSimilar(input,"food")) {
        cout << "Select a food\n";
        vector<string> foods = Food::getFoods();
        for (int i = 0; i < foods.size(); i++) {
            cout << "-" << foods[i] <<endl;
        }

        string foodInput;
        getline(cin, foodInput);
        bool foodFound = false;

        for (int i = 0; i < foods.size(); i++) {
            if (textSimilar(foodInput,foods[i])) {
                message = "\n-- Selected " + foods[i];
                //cout << "Press enter to apply\n";
                session.chooseFood(foods[i]);
                foodFound = true;

            }
        }
        if (!foodFound) {
            message = "Food not found";
        }
    }

    else if (textSimilar(input, "quit")) {
        string confirm;
        cout << "Quit without saving? \n Yes/No \n";
        cin >> confirm;
        if (textSimilar(confirm, "yes")) {
            cout << "\nGoodbye! o/";
            exit(1);
        }
    }

    else {
        message = "Unknown input \"" + input + "\" Type 'Help' for list of actions.\n";
    }

    system("cls");
    session.renderFrame();
    cout << endl << message <<endl;

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

    //system("cls");
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