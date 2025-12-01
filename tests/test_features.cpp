//
// Created by oinkh on 11/28/2025.
//

#include "Game.h"
#include "Palate.h"

#include <cassert>
#include <iostream>

//Test 1: normal operation
void testNormalOperation() {
    std::cout << "Testing normal operation.\n";

    //test making a pallete and printing
    Game testSession = Game();
    testSession.renderFrame();
    std::cout << "Passed with Game setup";

    Palate p = Palate(10,false);
    assert(p.getSize() == 10);
    assert(p.getGrid());
}

int main() {
    try {
        testNormalOperation();
    } catch (const std::exception& e) {
        std::cout << e.what()<<std::endl;
        return 1;
    }
}