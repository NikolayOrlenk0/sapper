#pragma once
 
#include <vector> 
 
class GameLogic { 
public: 
    GameLogic(int rows, int cols, int bombs); 
    bool is_revealed(int row, int col) const; 
    bool is_flagged(int row, int col) const; 
    bool reveal_cell(int row, int col); 
    void toggle_flag(int row, int col); 
    int remaining_flags() const; 
    bool has_flag(int row, int col) const;
private: 
    int rows_, cols_; 
    int bombs_; 
    std::vector<std::vector<int>> table_;  // Состояние клеток 
    std::vector<std::vector<bool>> revealed_;  // Является ли клетка открытой 
    std::vector<std::vector<bool>> flagged_;  // Есть ли флаг на клетке 
}; 