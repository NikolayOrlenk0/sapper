#include <iostream>
#include <vec/vec2d.h>
#include <table/table.h>
#include <table/bombs.h>
using namespace std;


int main(){
    constexpr int n = 15;
    constexpr int m = 10;
    Table table(n, m);
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
    const auto t = table.open_cells(Vec2d(0, 4));
    cout << t.size() << '\n';
    for(const auto& i : t){
        cout << i.first << " " << i.second << '\n';
    }
    return 0;
}