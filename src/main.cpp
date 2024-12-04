#include <iostream>
#include <vec/vec2d.h>
#include <table/table.h>
#include <table/bombs.h>
using namespace std;


int main(){
    constexpr int n = 5;
    constexpr int m = 2;
    Table table(n) ;
    Bombs bombs_kord;
    bombs_kord.bomb_XY(m);

    for(auto i : bombs_kord.bombs_kord){
        table.fill_table(i);
    }
    for(int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++){
            if(table[i][j].hasMine) {
                cout << "B" << " ";
            }
            else{
                cout << table[i][j].adjacentMines << " ";
            }
        }
        cout << '\n';
    }
    const auto t = table.open_nulls(Vec2d(3, 3));
    for(const auto& i : t){
        cout << i.x << " " << i.y << '\n';
    }
}