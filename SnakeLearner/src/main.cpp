#include <iostream>

#include "snake/SnakeGame.h"

int main() {

    auto score = SnakeGame::playAsHuman();
    std::cout << score << std::endl;
}
