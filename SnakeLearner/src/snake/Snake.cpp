#include <SDL.h>

#include "SnakeGame.h"
#include "Snake.h"

namespace SnakeGame {

    Snake::Snake() {
        static const int STARTING_LENGTH = 3;
        static const Coords STARTING_POS = { 10, 10 };

        for (auto i = 0; i != STARTING_LENGTH; ++i)
            _body.push_back({ STARTING_POS.x - i, STARTING_POS.y });
    }

    void Snake::move(Command command) {
        auto newHead = _body.front();
        switch (command) {
        case UP: --newHead.y; break;
        case DOWN: ++newHead.y; break;
        case LEFT: --newHead.x; break;
        case RIGHT: ++newHead.x; break;
        }
        _body.pop_back();
        _body.push_front(newHead);
    }

    void Snake::render(SDL_Renderer * renderer) {
        for (auto &segment : _body) {
            auto segmentRect = SDL_Rect{};
            segmentRect.x = segment.x * CELL_SIZE+1;
            segmentRect.y = segment.y * CELL_SIZE+1;
            segmentRect.w = segmentRect.h = CELL_SIZE-2;

            SDL_SetRenderDrawColor(renderer, 91, 47, 25, 255);
            SDL_RenderFillRect(renderer, &segmentRect);
        }
    }

    bool Snake::hasCollidedWithSelf() const {
        const auto &head = _body.front();
        auto it = _body.begin();
        ++it;
        for (; it != _body.end(); ++it) {
            if (*it == head)
                return true;
        }
        return false;
    }

}
