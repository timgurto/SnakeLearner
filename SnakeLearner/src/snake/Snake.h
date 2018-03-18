#pragma once

#include <list>

#include "SnakeGame.h"

struct SDL_Renderer;

namespace SnakeGame {

    class Snake {
    public:
        Snake();

        void move(Command command, Coords egg);
        void render(SDL_Renderer *renderer);
        bool hasCollidedWithSelf() const;
        bool isInBounds() const;
        Coords head() const { return _body.front(); }

    private:
        std::list<Coords> _body; // front = head
    };

}
