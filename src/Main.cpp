//
// Created by pigface on 11/22/2025.
//
#include <algorithm>
#include <iostream>
#include <cstdlib>

#include "../include/Game.h"
using namespace std;
int stringErrorMargin = 2;

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

bool textSimiliar(string a, string b) {

    std::transform(a.begin(), a.end(), a.begin(), ::tolower);
    a.erase(std::remove_if(a.begin(), a.end(), ::isspace), a.end());
    return (levenshteinRecursive(a,b,a.length(),b.length())<=stringErrorMargin );
}

bool interpretInput(string input) {

    system("cls");
    session.renderFrame();
    cout << endl;

    if (textSimiliar(input,"help")) {
        cout << "Help menu\n";
    }

    // if (input == "up") session.move(0,1);
    // else if (input == "down") session.move(0,-1);
    // else if (input == "left") session.move(-1,0);
    // else if (input == "right") session.move(1,0);
    //
    // else if (input == "select food") {  //TODO FEATURE 2
    //     //TODO food selection
    //     session.chooseFood("food");
    // }
    // else if (input == "dish up") session.applyFood();
    // else if (input == "serve") session.serveDish();
    // else if (input== "86") session.clearDish();

    else if (textSimiliar(input,"food")) {
        cout << "Select a food\n";

    }

    else if (textSimiliar(input, "quit")) {
        string confirm;
        cout << "Quit without saving? \n Yes/No \n";
        cin >> confirm;
        if (textSimiliar(confirm, "yes")) {
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