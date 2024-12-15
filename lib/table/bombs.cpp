#include "bombs.h"
#include <cstdlib>

void Bombs::bomb_XY(int h, int w, int m){
    for(int i = 0; i < m; i++){
        int id = rand() % (h * w);
        int x = id % h;
        int y = (id / h) % w;
        bombs_kord.push_back(Vec2d(x, y));
    }
}

int Bombs::size(){
    return bombs_kord.size();
}


