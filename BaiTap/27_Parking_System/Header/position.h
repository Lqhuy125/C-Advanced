#ifndef __POSITION_H
#define __POSITION_H

struct Position{
    int x, y;
    Position (int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(Position &other){
        return x == other.x && y == other.y;
    }
};

#endif