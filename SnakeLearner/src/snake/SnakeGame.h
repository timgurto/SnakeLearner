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

        Coords(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}

        bool operator==(const Coords &rhs) const {
            return x == rhs.x && y == rhs.y;
        }

        bool operator!=(const Coords &rhs) const {
            return ! (*this == rhs);
        }
    };

}
