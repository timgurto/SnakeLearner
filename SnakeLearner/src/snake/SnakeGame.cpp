#include "SnakeGame.h"
#include "Game.h"

int SnakeGame::playAsHuman() {
    auto game = Game::RandomGame();
    game.loop();
    return 0;
}
