#include "bombs.h"
#include <cstdlib>

void Bombs::bomb_XY(int h, int w, int m){
    for(int i = 0; i < m; i++){
        int id = rand() % (h * w);
        int x = id % h;
        int y = (id / h) % w;
        bool is_unik = true;
        for(auto &j : bombs_kord){
            if(j.x == x && j.y == y){
                m++;
                is_unik = false;
            }
        }
        if(is_unik){
            bombs_kord.push_back(Vec2d(x, y));
        }
    }
}

int Bombs::size(){
    return bombs_kord.size();
}


