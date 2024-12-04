#include <FL/Fl.H> 
#include <FL/Fl_Window.H> 
#include <FL/Fl_Button.H> 
#include <FL/Fl_Box.H> 
#include <FL/Fl_Output.H> 
#include <vector> 
#include "../table/bombs.h" // Подключаем бэкенд 
#include "../table/table.h"
#include "game_logic.h"
 
const int GRID_SIZE = 15; // Размер игрового поля 
const int CELL_SIZE = 30; 
 
class GameCell : public Fl_Button { 
public: 
    int row, col; 
    GameLogic& logic; 
 
    GameCell(int x, int y, int w, int h, int r, int c, GameLogic& logic_instance) 
        : Fl_Button(x, y, w, h), row(r), col(c), logic(logic_instance) { 
        this->box(FL_UP_BOX); 
        this->callback(cell_cb, this); 
    } 
 
    static void cell_cb(Fl_Widget* widget, void* data) { 
        GameCell* cell = (GameCell*)data; 
 
        if (Fl::event_button() == FL_LEFT_MOUSE) { 
            cell->reveal(); 
        } else if (Fl::event_button() == FL_RIGHT_MOUSE) { 
            cell->toggle_flag(); 
        } 
    } 
 
    void reveal() {
    bool result = logic.reveal_cell(row, col);
    if (!result) {
        return;  
    }
    this->label("Revealed");
}
 
    void toggle_flag() { 
        if (logic.is_revealed(row, col)) return; 
 
        logic.toggle_flag(row, col); // Бэкенд обрабатывает флажки 
        this->label(logic.has_flag(row, col) ? "F" : ""); 
    } 
}; 
 
class GameWindow : public Fl_Window { 
private: 
    std::vector<std::vector<GameCell*>> grid; 
    Fl_Output* bomb_counter; 
    Fl_Output* timer; 
    GameLogic logic; 
 
public: 
    GameWindow(int width, int height, const char* title) 
        : Fl_Window(width, height, title), logic(GRID_SIZE, GRID_SIZE, 40) { // 40 бомб 
        this->begin(); 
 
        bomb_counter = new Fl_Output(10, 10, 100, 30, "Бомбы:"); 
        bomb_counter->value(std::to_string(logic.remaining_flags()).c_str()); 
 
        timer = new Fl_Output(120, 10, 80, 30, "Время:"); 
        timer->value("0"); 
 
        for (int i = 0; i < GRID_SIZE; ++i) { 
            std::vector<GameCell*> row; 
            for (int j = 0; j < GRID_SIZE; ++j) { 
                GameCell* cell = new GameCell(10 + j * CELL_SIZE, 50 + i * CELL_SIZE, CELL_SIZE, CELL_SIZE, i, j, logic); 
                row.push_back(cell); 
            } 
            grid.push_back(row); 
        } 
 
        this->end(); 
    } 
};
