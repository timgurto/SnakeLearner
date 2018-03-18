#pragma once

struct SDL_Renderer;
struct SDL_Window;

#include "Snake.h"
#include "SnakeGame.h"

namespace SnakeGame {

    class Game {
    public:
        static Game RandomGame();
        ~Game();

        void loop();
        void update(Command command);
        void render();

        int score() const { return _score; }

    private:
        using GetCommandFunction = Command(*)();
        Game(GetCommandFunction getCommandFunction);

        Snake _snake;
        int _score{ 0 };
        
        bool isGameOver() const;

        GetCommandFunction _getNextCommand { nullptr };

        static Command getRandomCommand();
        static Command getCommandFromUser();
        static Command getCommandFromNetwork();

        SDL_Window *_window{ nullptr };
        SDL_Renderer *_renderer{ nullptr };
    };

}
