#include <iostream>

#include "snake/Snake.h"

int main() {
    auto score = Snake::playAsHuman();
    std::cout << score << std::endl;
}