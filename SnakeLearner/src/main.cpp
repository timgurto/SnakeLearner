#include <iostream>

#include "snake/Game.h"
#include "neural-network/Network.h"

int main() {
    {
    auto game = SnakeGame::Game::RandomGame();
    game.loop();

    std::cout << game.score() << std::endl;
    }
    {
        auto network = NeuralNetwork::Network{};
        auto game = SnakeGame::Game::NetworkGame(network);
        game.loop();

        std::cout << game.score() << std::endl;
    }
}
