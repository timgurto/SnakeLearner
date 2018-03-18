#include <algorithm>
#include <iostream>

#include <SDL.h>

#include "snake/Game.h"
#include "neural-network/Network.h"

SDL_Window *window{ nullptr };
SDL_Renderer *renderer{ nullptr };

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    const auto WIN_SIZE = SnakeGame::GRID_SIZE * SnakeGame::CELL_SIZE;
    window = SDL_CreateWindow("Snake", 10, 20, WIN_SIZE, WIN_SIZE, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    static const int POPULATION_SIZE = 10000;

    // Create first generation randomly
    auto generation = 1;
    std::vector<NeuralNetwork::Network> population;
    for (auto i = 0; i != POPULATION_SIZE; ++i)
        population.push_back(NeuralNetwork::Network{ {400, 12, 12, 4} });

    while (true) {
        // Test with each
        auto maxScore = -1;
        auto minScore = -1;
        for (const auto &network : population) {
            auto game = SnakeGame::Game::NetworkGame(network);
            game.loop();
            network.setScore(game.score());
            if (game.score() > maxScore)
                maxScore = game.score();
            if (minScore == -1 || game.score() < minScore)
                minScore = game.score();
        }
        std::cout << "Generation " << generation
            << ": best=" << maxScore
            << " worst=" << minScore << std::endl;

        // Sort
        std::sort(population.rbegin(), population.rend());

        // Cull bottom 75%
        auto newSize = population.size() * 1 / 4;
        population.resize(newSize);

        // Mutate each 3 times
        for (auto i = 0; i != newSize; ++i) {
            for (auto i = 0; i != 3; ++i) {
                auto child = population[i];
                child.mutate();
                population.push_back(child);
            }
        }

        // Repeat
        ++generation;
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
