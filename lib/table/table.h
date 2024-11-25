#pragma once
#include "../vec/vec2d.h"
#include <vector>
#include <iostream>



class Table{
private:
    std::vector<std::vector<int>> _table;
public:
    Table(int n){
        _table.resize(n, std::vector<int>(n));
    }

    void fill_table(Vec2d bomb);
    std::vector<Vec2d> open_nulls(Vec2d point);
    int size();
    std::vector<int>& operator[](size_t i);
};
