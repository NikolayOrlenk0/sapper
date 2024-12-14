#include "bombs.h"
#include "table.h"
#include <iostream>
#include <queue>
#include <vector>


using namespace std;

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


vector<Vec2d> Table::open_nulls(Vec2d point){
    queue<pair<Vec2d, Vec2d>> nulls;
    nulls.push(make_pair(Vec2d(point.x, point.y), Vec2d(-1, -1)));
    vector<Vec2d> v;
    while(!nulls.empty()) {
        point = nulls.front().first;
        Vec2d prev = nulls.front().second;
        nulls.pop();
        for (int dx = -1; dx < 2; dx++) {
            for (int dy = -1; dy < 2; dy++) {
                if (labs(dx) != labs(dy)) {
                    if ((0 <= point.x + dx && point.x + dx < _table[0].size()) &&
                    (0 <= point.y + dy && point.y + dy < _table.size())) {

                        if ((!_table[point.x + dx][point.y + dy].isRevealed) &&
                            (Vec2d(point.x + dx, point.y + dy) != prev) &&
                            (_table[prev.x][prev.y].adjacentMines == 0 || (prev.x == -1 && prev.y == -1))
                          ) {
                            nulls.push(make_pair(Vec2d(point.x + dx, point.y + dy), point));
                            _table[point.x + dx][point.y + dy].isRevealed = true;
                        }
                    }
                }
            }
        }
        v.push_back(point);
    }
    return v;
}


//std::vector<Cell>& Table::operator[](size_t i){
//    return _table[i];
//}


int Table::size(){
    return _table.size();
}

void Table::toggle_flag(Vec2d point){
  _table[point.x][point.y].hasFlag = !_table[point.x][point.y].hasFlag;

}

bool Table::is_flag(Vec2d point){
	return !_table[point.x][point.y].hasFlag;
}
