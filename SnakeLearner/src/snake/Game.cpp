#include <SDL.h>

#include "Game.h"
#include "SnakeGame.h"

namespace SnakeGame {

    Game::Game(GetCommandFunction getCommandFunction) {
        SDL_Init(SDL_INIT_VIDEO);

        const auto WIN_SIZE = GRID_SIZE * CELL_SIZE;
        _window = SDL_CreateWindow("Snake", 10, 20, WIN_SIZE, WIN_SIZE, SDL_WINDOW_SHOWN);
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

        _getNextCommand = getCommandFunction;
    }

    Game Game::RandomGame() {
        return Game(&getRandomCommand);
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

    Command Game::getRandomCommand() {
        auto cmd = rand() % 4;
        switch (cmd) {
        case 0: return UP;
        case 1: return DOWN;
        case 2: return LEFT;
        case 3: return RIGHT;
        }

        return UP;
    }
}
