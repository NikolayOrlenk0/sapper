#include <iostream>
#include <vec/vec2d.h>
#include <table/table.h>
#include <table/bombs.h>
using namespace std;


int main(){
    constexpr int n = 15;
    constexpr int m = 10;
    Table table(n, m);
    // cout << bombs_kord.bombs_kord.size() << endl;
    // for (auto i: bombs_kord.bombs_kord) {
    //     cout << i.x << ", " << i.y << endl;
    // }
    // for(int i = 0; i < table.size(); i++) {
    //     for (int j = 0; j < table[i].size(); j++){
    //         if(table[i][j].hasMine) {
    //             cout << "B" << " ";
    //         }
    //         else{
    //             cout << table[i][j].adjacentMines << " ";
    //         }
    //     }
    //     cout << '\n';
    // }
    const auto t = table.open_nulls(Vec2d(1, 3));
    // for(const auto& i : t){
    //     cout << i.x << " " << i.y << '\n';
    // }

}