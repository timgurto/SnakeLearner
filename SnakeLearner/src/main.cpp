#include <iostream>

#include "snake/Game.h"

int main() {
    auto score = Snake::playAsHuman();
    std::cout << score << std::endl;
}