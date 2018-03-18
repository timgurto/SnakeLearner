#pragma once

struct SDL_Renderer;
struct SDL_Window;

namespace Snake {
    static const int
        GRID_SIZE{ 20 },
        CELL_SIZE{ 5 };

    int playAsHuman();

    class Game {
    public:
        Game();
        ~Game();

    private:

        SDL_Window *_window{ nullptr };
        SDL_Renderer *_renderer{ nullptr };
    };

}
