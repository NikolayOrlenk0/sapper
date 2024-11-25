#pragma once
#include <std_lib_facilities.h>
#include "../vec/vec2d.h"

class Bombs{
public:
    vector<Vec2d> bombs_kord;
    void bomb_XY(int n);
    int size();
};
