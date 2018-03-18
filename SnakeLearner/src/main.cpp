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

    auto max = -1;

    for (auto i = 0; i != 500; ++i) {
        auto network = NeuralNetwork::Network{ {400, 12, 12, 4} };
        auto game = SnakeGame::Game::NetworkGame(network);
        game.loop();
        std::cout << game.score() << std::endl;
        if (game.score() > max)
            max = game.score();
    }

    std::cout << "Max score: " << max << std::endl;


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
