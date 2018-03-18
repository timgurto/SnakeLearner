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

    int playAsHuman();

}
