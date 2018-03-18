#include "SnakeGame.h"
#include "Game.h"

int SnakeGame::playAsHuman() {
    Game g{};
    g.render();
    while (true);
    return 0;
}
