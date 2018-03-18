#pragma once

struct SDL_Renderer;
struct SDL_Window;

#include "Snake.h"
#include "SnakeGame.h"
#include "../neural-network/Network.h"

namespace SnakeGame {

    class Game {
    public:
        static Game RandomGame();
        static Game NetworkGame(const NeuralNetwork::Network &network);

        void loop();
        void update(Command command);
        void render();

        int score() const { return _score; }

    private:
        using GetCommandFunction = Command(*)(const Game&);
        Game(GetCommandFunction getCommandFunction);

        Snake _snake;
        int _score{ 0 };

        Coords _egg{ 5, 5 };

        const NeuralNetwork::Network * _network{ nullptr };
        NeuralNetwork::Values compileGameStateIntoInputVector() const;
        
        bool isGameOver() const;

        GetCommandFunction _getNextCommand { nullptr };

        static Command getRandomCommand(const Game &game);
        static Command getCommandFromUser(const Game &game);
        static Command getCommandFromNetwork(const Game &game);
    };

}
