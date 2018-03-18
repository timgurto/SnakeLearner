#pragma once

#include <list>

#include "SnakeGame.h"

struct SDL_Renderer;

namespace SnakeGame {

    class Snake {
    public:
        Snake();

        void move(Command command);
        void render(SDL_Renderer *renderer);

    private:
        std::list<Coords> _body; // front = head

    };

}
