//
// Created by pigface on 11/22/2025.
//
#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

#include "../include/Food.h"
#include "../include/Game.h"
using namespace std;
int stringErrorMargin = 1;

Game session = Game(0,0);

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
    std::stringstream stream;

    string message = "What would you like to do next? Type 'Help' for list of actions.";

    if (textSimilar(input,"help")) {
        message = "Help menu:\n\n";

        message += "'Food'- opens food menu.\n";
        message += "'Cook'- cooks food and moves it up on the board.\n";
        message += "'Lemon'- adds lemon to the food and moves it down on the board.\n";
        message += "'Oil'- adds olive oil to the food and moves it left on the board.\n";
        message += "'Water'- adds water to the food and moves it right on the board.\n";
        message += "'Plate'- plates current food to dish.\n";
        message += "'86'- clear the dish.\n";
        message += "'Serve' -Serves the dish to the customer.\n";

        message += "\n'Quit' - quit game without saving. (game autosaves after each customer)"; //TODO not yet lol
    }

    else if (textSimilar(input,"w") or textSimilar(input,"cook")) session.move(0,-1);
    else if (textSimilar(input, "s") or textSimilar(input,"lemon")) session.move(0,1);
    else if (textSimilar(input, "a") or textSimilar(input,"oil")) session.move(-1,0);
    else if (textSimilar(input, "d") or textSimilar(input,"water")) session.move(1,0);

    else if (textSimilar(input,"plate")) session.applyFood();
    else if (textSimilar(input,"86")) session.clearDish();

    else if (textSimilar(input, "serve")) {
        float pay = session.completeOrder();
        stream << std::fixed << std::setprecision(2) << pay;
        message = "Order served. Your were paid $" + stream.str();
    }

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

    //session.chooseFood("gibberish");
    //session.move(2,1);

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