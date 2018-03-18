#pragma once

struct SDL_Renderer;
struct SDL_Window;

#include "Snake.h"

namespace SnakeGame {
    static const int
        GRID_SIZE{ 20 },
        CELL_SIZE{ 5 };

    int playAsHuman();

    class Game {
    public:
        Game();
        ~Game();

        void render();

    private:
        Snake _snake;

        SDL_Window *_window{ nullptr };
        SDL_Renderer *_renderer{ nullptr };
    };

}
