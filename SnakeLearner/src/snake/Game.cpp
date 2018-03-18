#include <SDL.h>

#include "Game.h"

namespace SnakeGame {

    Game::Game() {
        SDL_Init(SDL_INIT_VIDEO);

        const auto WIN_SIZE = GRID_SIZE * CELL_SIZE;
        _window = SDL_CreateWindow("Snake", 10, 15, WIN_SIZE, WIN_SIZE, SDL_WINDOW_SHOWN);
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    }

    Game::~Game() {
        SDL_DestroyRenderer(_renderer);
        SDL_DestroyWindow(_window);
        SDL_Quit();
    }

    void Game::render() {
        SDL_SetRenderDrawColor(_renderer, 53, 127, 81, 255);
        SDL_RenderClear(_renderer);

        _snake.render(_renderer);

        SDL_RenderPresent(_renderer);
    }

    int playAsHuman() {
        Game g{};
        g.render();
        while (true);
        return 0;
    }

}
