#include "table.h"
#include <iostream>
#include <queue>

using namespace std;

void Table::fill_table(Vec2d bomb){
    _table[bomb.x][bomb.y] = -1;
    for(int dx = -1; dx < 2; dx++){
        for(int dy = -1; dy < 2; dy++){
            if(dx != 0 || dy != 0) {
                if ((0 <= bomb.x + dx && bomb.x + dx < _table[0].size())
                && (0 <= bomb.y + dy && bomb.y + dy < _table.size())) {
                    if(_table[bomb.x + dx][bomb.y + dy] != 9)
                        _table[bomb.x + dx][bomb.y + dy]++;
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
                    if ((0 <= point.x + dx && point.x + dx < _table[0].size()) && (0 <= point.y + dy && point.y + dy < _table.size())) {
                        if ((!_table[point.x + dx][point.y + dy]) && (Vec2d(point.x + dx, point.y + dy) != prev)) {
                            nulls.push(make_pair(Vec2d(point.x + dx, point.y + dy), point));
                            _table[point.x + dx][point.y + dy] = -2;
                        }
                    }
                }
            }
        }
        v.push_back(point);

    }
    return v;
}


std::vector<int>& Table::operator[](size_t i){
    return _table[i];
}


int Table::size(){
    return _table.size();
}