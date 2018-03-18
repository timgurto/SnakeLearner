#include <SDL.h>

#include "Game.h"

Snake::Game::Game() {
    SDL_Init(SDL_INIT_VIDEO);
}

Snake::Game::~Game() {
    SDL_Quit();
}

int Snake::playAsHuman() {
    return 0;
}
