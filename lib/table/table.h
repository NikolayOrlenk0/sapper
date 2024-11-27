#pragma once
#include "../vec/vec2d.h"
#include <vector>
#include <iostream>
#include "grid/grid.h"



class Table{
private:
    std::vector<std::vector<Cell>> _table;
public:
    Table(int n){
        _table.resize(n, std::vector<Cell>(n));
    }

    void fill_table(Vec2d bomb);
    std::vector<Vec2d> open_nulls(Vec2d point);
    int size();
    std::vector<Cell>& operator[](size_t i);
};
