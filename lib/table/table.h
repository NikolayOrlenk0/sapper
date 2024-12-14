#pragma once
#include "bombs.h"
#include "../vec/vec2d.h"
#include <vector>
#include <iostream>
#include <ostream>

#include "grid/grid.h"

using namespace std;

class Table{
private:
    vector<vector<Cell>> _table;
public:
    Table(int n, int m){
        _table.resize(n, vector<Cell>(n));
        Bombs bombs_kord;
        bombs_kord.bomb_XY(m);
        for(auto i : bombs_kord.bombs_kord){
            fill_table(i);
        }
    }

    void fill_table(Vec2d bomb);
    vector<Vec2d> open_cells(Vec2d point);
    int size();
    vector<Cell>& operator[](size_t i) {
            return _table[i];
    }
    void toggle_flag(Vec2d point);
    bool is_flag(Vec2d point);
    bool is_mine(Vec2d point);
    const char adjacent_mines(Vec2d point);
    bool is_revealed(Vec2d point);
};


