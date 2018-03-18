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
        bool hasCollidedWithSelf() const;
        bool isInBounds() const;

    private:
        std::list<Coords> _body; // front = head
    };

}
