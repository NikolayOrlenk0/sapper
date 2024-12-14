#pragma once
#include "bombs.h"
#include "../vec/vec2d.h"
#include <vector>
#include <iostream>
#include <ostream>
#include "grid/grid.h"
#include <set>


class Table{
private:
    std::vector<std::vector<Cell>> _table;
public:
    Table(int n, int m){
        _table.resize(n, std::vector<Cell>(n));
        Bombs bombs_kord;
        bombs_kord.bomb_XY(n, m);
        for(auto i : bombs_kord.bombs_kord){
            fill_table(i);
        }
    }

    void fill_table(Vec2d bomb);
    std::set<std::pair<int, int>> open_cells(Vec2d point);
    int size();
    std::vector<Cell>& operator[](size_t i) {
            return _table[i];
    }
    void toggle_flag(Vec2d point);
    bool is_flag(Vec2d point);
    bool is_mine(Vec2d point);
    std::string adjacent_mines(Vec2d point);
    bool is_revealed(Vec2d point);
};


