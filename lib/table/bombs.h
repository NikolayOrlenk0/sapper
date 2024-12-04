#pragma once
#include <vector>
#include "../vec/vec2d.h"

class Bombs{
public:
    std::vector<Vec2d> bombs_kord;
    void bomb_XY(int n);
    int size();
};
