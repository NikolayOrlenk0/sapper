#include "game_logic.h" 
#include <iostream> 
#include <cstdlib> // Для rand() 
 
GameLogic::GameLogic(int rows, int cols, int bombs) 
    : rows_(rows), cols_(cols), bombs_(bombs) { 
    table_.resize(rows, std::vector<int>(cols, 0)); 
    revealed_.resize(rows, std::vector<bool>(cols, false)); 
    flagged_.resize(rows, std::vector<bool>(cols, false)); 
 
    // Логика для расставления бомб 
    for (int i = 0; i < bombs_; ++i) { 
        int row = rand() % rows_; 
        int col = rand() % cols_; 
        table_[row][col] = -1;  // -1 означает бомбу 
    } 
} 
 
bool GameLogic::reveal_cell(int row, int col) {
    // Логика раскрытия клетки, например:
    if (is_revealed(row, col)) {
        return false;  // Если клетка уже раскрыта, возвращаем false
    }
    
    // Логика раскрытия клетки
    table_[row][col] = /* раскрытое состояние */;
    return true;  // Возвращаем true, если клетка успешно раскрыта
}

bool GameLogic::is_revealed(int row, int col) const { 
    return revealed_[row][col]; 
} 
 
bool GameLogic::is_flagged(int row, int col) const { 
    return flagged_[row][col]; 
} 
 
void GameCell::reveal() {    if (logic.is_revealed(row, col)) return;
    logic.reveal_cell(row, col);  // Просто вызываем метод без присваивания}
}

void GameCell::toggle_flag() 
{
    if (logic.is_revealed(row, col)) return;    logic.toggle_flag(row, col);  // Обработка флага
    this->label(logic.has_flag(row, col) ? "F" : "");  // Обновление метки с флагом}
}

int GameLogic::remaining_flags() const { 
    int count = 0; 
    for (int i = 0; i < rows_; ++i) { 
        for (int j = 0; j < cols_; ++j) { 
            if (flagged_[i][j]) { 
                count++; 
            } 
        } 
    } 
    return count; 
}

bool GameLogic::has_flag(int row, int col) const {
    return flagged_[row][col];
}