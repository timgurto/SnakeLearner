#include <iostream>

#include "snake/Game.h"

int main() {

    auto score = SnakeGame::playAsHuman();
    std::cout << score << std::endl;
}
