#include "SnakeGame.h"
#include "Game.h"

int SnakeGame::playAsHuman() {
    auto game = Game::RandomGame();
    game.render();
    while (true);
    return 0;
}
