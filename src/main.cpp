#include <iostream>
#include <vec/vec2d.h>
#include <table/table.h>
#include <table/bombs.h>
using namespace std;


int main(){
    int n, m;
    n = 5;
    m = 2;
    Table table(5) ;
    Bombs bombs_kord;
    bombs_kord.bomb_XY(m);

    for(auto i : bombs_kord.bombs_kord){
        table.fill_table(i);
    }
    table.open_nulls(Vec2d(3, 3));

}