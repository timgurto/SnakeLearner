#include <cassert>

#include <SDL.h>

#include "Game.h"
#include "SnakeGame.h"
#include "../neural-network/Network.h"

extern SDL_Renderer *renderer;

namespace SnakeGame {

    Game::Game(GetCommandFunction getCommandFunction) {
        _getNextCommand = getCommandFunction;
    }

    Game Game::RandomGame() {
        return Game(&getRandomCommand);
    }

    Game Game::NetworkGame(const NeuralNetwork::Network &network) {
        auto game = Game(&getCommandFromNetwork);
        game._network = &network;
        return game;
    }

    void Game::loop() {
        while (true) {
            render();

            auto command = _getNextCommand(*this);
            update(command);

            if (isGameOver())
                break;

            ++_score;

            SDL_Delay(10);
        }
    }

    void Game::update(Command command) {
        _snake.move(command, _egg);

        if (_snake.head() == _egg) {
            _score += 1000;

            auto newEggLoc = Coords{};
            do {
                newEggLoc.x = rand() % GRID_SIZE;
                newEggLoc.y = rand() % GRID_SIZE;
            } while (newEggLoc == _egg);
            _egg = newEggLoc;
        }
    }

    void Game::render() {
        SDL_SetRenderDrawColor(renderer, 53, 127, 81, 255);
        SDL_RenderClear(renderer);

        _snake.render(renderer);

        SDL_SetRenderDrawColor(renderer, 249, 241, 199, 255);
        auto eggRect = SDL_Rect{};
        eggRect.x = _egg.x * CELL_SIZE + 1;
        eggRect.y = _egg.y * CELL_SIZE + 1;
        eggRect.w = eggRect.h = CELL_SIZE - 2;
        SDL_RenderFillRect(renderer, &eggRect);

        SDL_RenderPresent(renderer);
    }

    NeuralNetwork::Values Game::compileGameStateIntoInputVector() const {
        auto ret = NeuralNetwork::Values{};
        for (auto i = 0; i != 400; ++i)
            ret.push_back(0.5);
        return ret;
    }

    bool Game::isGameOver() const {
        if (_snake.hasCollidedWithSelf())
            return true;
        if (!_snake.isInBounds())
            return true;
        return false;
    }

    Command Game::getRandomCommand(const Game &) {
        auto cmd = rand() % 4;
        switch (cmd) {
            case 0: return UP;
            case 1: return DOWN;
            case 2: return LEFT;
            case 3: return RIGHT;
        }

        return UP;
    }
    Command Game::getCommandFromNetwork(const Game &game) {
        assert(game._network);
        auto &network = *game._network;

        auto input = game.compileGameStateIntoInputVector();

        auto output = network.calculate(input);
        assert(output.size() == 4);

        auto maxIndex = 0;
        auto maxVal = NeuralNetwork::Value{ 0 };
        for (auto i = 1; i != output.size(); ++i) {
            if (output[i] > maxVal) {
                maxVal = output[i];
                maxIndex = i;
            }
        }

        switch (maxIndex) {
            case 0: return UP;
            case 1: return DOWN;
            case 2: return LEFT;
            case 3: return RIGHT;
        }

        return UP;
    }
}
