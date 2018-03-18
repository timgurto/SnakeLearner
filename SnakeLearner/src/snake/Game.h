#pragma once

struct SDL_Renderer;
struct SDL_Window;

#include "Snake.h"

namespace SnakeGame {

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
