#include "bombs.h"
#include <cstdlib>

void Bombs::bomb_XY(int n, int m){
    for(int i = 0; i < m; i++){
        int id = rand() % (n * n);
        int x = id % n;
        int y = (id / n) % n;
        bombs_kord.push_back(Vec2d(x, y));
    }
}

int Bombs::size(){
    return bombs_kord.size();
}


