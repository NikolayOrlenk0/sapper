#pragma once

#include <exception>
#include <iostream>
#include <vector>
#include <FL/Fl.H> 
#include <FL/Fl_Window.H> 
#include <FL/Fl_Button.H> 

struct Cell 
{
    bool hasMine = false;       // Есть ли мина 
    bool isRevealed = false;    // Открыта ли клетка 
    bool hasFlag = false;       // Установлен ли флаг 
    int adjacentMines = 0;     // Количество соседних мин 
};

struct Settings
{
    std::tuple<int, int> resolution;
    std::tuple<int,int> size_of_table;
    int count_of_bombs;
};

class CustomButton : public Fl_Button { 
public: 
 
    CustomButton(int X, int Y, int W, int H, Cell &cell): Fl_Button(X, Y, W, H), cell(cell) {}
    
    
     
    int handle(int event) override {
        switch (event) { 
        case FL_PUSH: { 
            if (Fl::event_button() == FL_LEFT_MOUSE) { 
                handleLeftClick(); 
            } else if (Fl::event_button() == FL_RIGHT_MOUSE) { 
                handleRightClick(); 
            } 
            return 1; // Указываем, что событие обработано 
        } 
        default: 
            return Fl_Button::handle(event); 
        } 
    } 
 
private: 

    Cell *cell;
    Fl_Button *button;

    void handleLeftClick() { 
        if (cell->isRevealed || cell->hasFlag) return; 
 
        if (cell->hasMine) { 
            label("X"); 
            deactivate();
        } else { 
            cell->isRevealed = true; 
            if (cell->adjacentMines > 0) { 
                label(std::to_string(cell->adjacentMines).c_str()); 
            } else { 
                label(""); 
            } 
            color(FL_GRAY); 
            deactivate();
        } 
        redraw(); 
    } 
 
    void handleRightClick() { 
 
        if (cell->isRevealed) return; 
 
        cell->hasFlag = !cell->hasFlag; 
        label(cell->hasFlag ? "f" : ""); 
        redraw(); 
    } 
}; 

struct My_window: CustomButton
{   
    Settings settings;
    My_window(int w, int h);
    std::vector<std::vector<Cell>> table;
    std::vector<std::vector<CustomButton>> playground;
    
    void generation_table()

    private:
    void quit () { hide(); }

};
