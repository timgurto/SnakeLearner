#include <cassert>
#include <iostream>

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

        static const double
            NOTHING = 0.0,
            BODY = 0.33,
            HEAD = 0.67,
            EGG = 1.0;

        for (auto i = 0; i != 400; ++i)
            ret.push_back(NOTHING);

        ret[to1D(_egg)] = EGG;
        ret[to1D(_snake.head())] = HEAD;

        auto it = _snake.body().begin();
        ++it;
        for (; it != _snake.body().end(); ++it)
            ret[to1D(*it)] = BODY;

        return ret;
    }

    size_t Game::to1D(Coords coords) {
        return coords.y * GRID_SIZE + coords.x;
    }

    bool Game::isGameOver() const {
        if (_snake.hasCollidedWithSelf())
            return true;
        if (!_snake.isInBounds())
            return true;
        if (_numTurns >= MAX_TURNS)
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
        auto maxVal = output[0];
        for (auto i = 1; i != output.size(); ++i) {
            if (output[i] > maxVal) {
                maxVal = output[i];
                maxIndex = i;
            }
        }

        /*std::cout << "Result from network: "
            << output[0] << ", "
            << output[1] << ", "
            << output[2] << ", "
            << output[3] << std::endl;*/

        switch (maxIndex) {
            case 0: return UP;
            case 1: return DOWN;
            case 2: return LEFT;
            case 3: return RIGHT;
        }

        return UP;
    }
}
