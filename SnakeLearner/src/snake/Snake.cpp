#include <SDL.h>

#include "Game.h"
#include "Snake.h"

namespace SnakeGame {

    Snake::Snake() {
        static const int STARTING_LENGTH = 3;
        static const Coords STARTING_POS = { 10, 10 };

        for (auto i = 0; i != STARTING_LENGTH; ++i)
            _body.push_back({ STARTING_POS.x - i, STARTING_POS.y });
    }

    void Snake::render(SDL_Renderer * renderer) {
        for (auto &segment : _body) {
            auto segmentRect = SDL_Rect{};
            segmentRect.x = segment.x * CELL_SIZE;
            segmentRect.y = segment.y * CELL_SIZE;
            segmentRect.w = segmentRect.h = CELL_SIZE;

            SDL_SetRenderDrawColor(renderer, 91, 47, 25, 255);
            SDL_RenderFillRect(renderer, &segmentRect);
        }
    }

}
