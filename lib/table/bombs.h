#pragma once
#include "../vec/vec2d.h"
#include <vector>


class Bombs{
public:
    std::vector<Vec2d> bombs_kord;
    void bomb_XY(int h, int w, int m);
    int size();
};
