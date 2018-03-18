#include <iostream>

#include "snake/Game.h"

int main() {

    auto game = SnakeGame::Game::RandomGame();
    game.loop();

    std::cout << game.score() << std::endl;
}
