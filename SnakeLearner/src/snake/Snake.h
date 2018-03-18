#pragma once

#include <list>

#include "util.h"

struct SDL_Renderer;

namespace SnakeGame {

    class Snake {
    public:
        Snake();

        void render(SDL_Renderer *renderer);

    private:
        std::list<Coords> _body; // front = head

    };

}
