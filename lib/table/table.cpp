#include "bombs.h"
#include "table.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>

void Table::regeneration_table(){
        _table.clear();
        _table.resize(settings.GRID_HEIGHT, std::vector<Cell>(settings.GRID_WIDTH));
        Bombs bombs_kord;
        bombs_kord.bomb_XY(settings.GRID_HEIGHT, settings.GRID_WIDTH, settings.COUNT_OF_BOMBS);
        for(auto i : bombs_kord.bombs_kord){
            fill_table(i);
        }
}



void Table::fill_table(Vec2d bomb){
    _table[bomb.x][bomb.y].hasMine = true;
    _table[bomb.x][bomb.y].adjacentMines = -1;
    for(int dx = -1; dx < 2; dx++){
        for(int dy = -1; dy < 2; dy++){
            if(dx != 0 || dy != 0) {
                if ((0 <= bomb.x + dx && bomb.x + dx < _table[0].size())
                && (0 <= bomb.y + dy && bomb.y + dy < _table.size())) {
                    if(!_table[bomb.x + dx][bomb.y + dy].hasMine)
                        _table[bomb.x + dx][bomb.y + dy].adjacentMines++;
                }
            }
        }
    }
}


std::set<std::pair<int, int>> Table::open_cells(Vec2d point){
  	std::set<std::pair<int, int>> v;
  	if(_table[point.x][point.y].hasMine){
          std::cerr << "YOU LOOSE" << std::endl;
    }
    else if(_table[point.x][point.y].adjacentMines > 0){
    	v.insert(std::make_pair(point.x, point.y));
        return v;
    }
    std::queue<std::pair<Vec2d, Vec2d>> nulls;
    nulls.push(std::make_pair(Vec2d(point.x, point.y), Vec2d(-1, -1)));

    while(!nulls.empty()) {
        point = nulls.front().first;
        Vec2d prev = nulls.front().second;
        nulls.pop();
        for (int dx = -1; dx < 2; dx++) {
            for (int dy = -1; dy < 2; dy++) {
                if ((0 <= point.x + dx && point.x + dx < _table.size()) &&
                (0 <= point.y + dy && point.y + dy < _table[0].size())) {
                    if ((!_table[point.x + dx][point.y + dy].isRevealed) &&
                      (!_table[point.x + dx][point.y + dy].hasMine) &&
                      (_table[point.x][point.y].adjacentMines == 0 || (prev.x == -1 && prev.y == -1))){
                        nulls.push(std::make_pair(Vec2d(point.x + dx, point.y + dy), point));
                        _table[point.x][point.y].isRevealed = true;
                    }
                }
            }
        }
        v.insert(std::make_pair(point.x, point.y));
    }
    return v;
}





int Table::size(){
    return _table.size();
}

void Table::toggle_flag(Vec2d point){
  _table[point.x][point.y].hasFlag = !_table[point.x][point.y].hasFlag;
}
bool Table::check_win(){
  for(int i = 0; i < _table.size(); i++){
    for(int j = 0; j < _table[i].size(); j++){
      if( !(_table[i][j].hasFlag) || !(_table[i][j].hasMine)){
        return false;
      }
    }
  }
  return true;
}
bool Table::is_flag(Vec2d point){
	return _table[point.x][point.y].hasFlag;
}

bool Table::is_mine(Vec2d point){
  return _table[point.x][point.y].hasMine;
}

std::string Table::adjacent_mines(Vec2d point){
  return std::to_string(_table[point.x][point.y].adjacentMines);
}

bool Table::is_revealed(Vec2d point){
  return _table[point.x][point.y].isRevealed;
}

