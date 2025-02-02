#pragma once
#include "bombs.h"
#include "../vec/vec2d.h"
#include <vector>
#include <iostream>
#include <ostream>
#include "grid/grid.h"
#include<table/settings.h>
#include <set>


class Table{
private:
    std::vector<std::vector<Cell>> _table;
    int flags_counter;
public:
    Settings settings;
    Table(){
        _table.resize(settings.GRID_HEIGHT, std::vector<Cell>(settings.GRID_WIDTH));
        Bombs bombs_kord;
        bombs_kord.bomb_XY(settings.GRID_HEIGHT, settings.GRID_WIDTH, settings.COUNT_OF_BOMBS);
        for(auto i : bombs_kord.bombs_kord){
            fill_table(i);
        }
    }



    void fill_table(Vec2d bomb);
    std::set<std::pair<int, int>> open_cells(Vec2d point);
    int size();
    std::vector<Cell>& operator[](size_t i);
    void toggle_flag(Vec2d point);
    bool is_flag(Vec2d point);
    bool is_mine(Vec2d point);
    int adjacent_mines(Vec2d point);
    bool is_revealed(Vec2d point);
    void regeneration_table(Vec2d);
    bool check_win();
};


