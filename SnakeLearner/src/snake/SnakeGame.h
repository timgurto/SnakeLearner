#pragma once

namespace SnakeGame {

    static const int
        GRID_SIZE{ 20 },
        CELL_SIZE{ 20 };

    enum Command {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    struct Coords {
        int x{ 0 };
        int y{ 0 };

        Coords(int x_, int y_) : x(x_), y(y_) {}
    };

    int playAsHuman();

}
