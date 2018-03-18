#include <SDL.h>

#include "Game.h"

Snake::Game::Game() {
    SDL_Init(SDL_INIT_VIDEO);

    const auto WIN_SIZE = GRID_SIZE * CELL_SIZE;
    _window = SDL_CreateWindow("Snake", 10, 15, WIN_SIZE, WIN_SIZE, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

Snake::Game::~Game() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

int Snake::playAsHuman() {
    Game{};
    return 0;
}
