#include "bombs.h"

using namespace std;

void Bombs::bomb_XY(int n){
    for(int i = 0; i < n; i++){
        int id = rand() % (n * n);
        int x = id % 15;
        int y = id / 15;
        bombs_kord.push_back(Vec2d(x, y));
    }
}

int Bombs::size(){
    return bombs_kord.size();
}

