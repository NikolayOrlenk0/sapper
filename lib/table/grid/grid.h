#pragma once

struct Cell
{
    bool hasMine = false;       // Есть ли мина
    bool isRevealed = false;    // Открыта ли клетка
    bool hasFlag = false;       // Установлен ли флаг
    int adjacentMines = 0;     // Количество соседних мин
    Cell(bool par1, bool par2, int par4){
        hasMine = par1;
        isRevealed = par2;
        adjacentMines = par4;
    }
    Cell(){
        bool isRevealed = false;
        bool hasFlag = false;
        int adjacentMines = 0;
    }
};