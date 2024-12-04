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
    int adjacentMines = 0;      // Количество соседних мин 

    Cell(bool h_m, bool isR, bool h_f, int mines): hasMine{h_m}, isRevealed{isR}, hasFlag{h_f}, adjacentMines{mines};
};


struct Settings
{
    std::tuple<int, int> resolution;
    std::tuple<int,int> size_of_table;
    int difficult;
};

class CustomButton : public Fl_Button { 
public: 
    
    Fl_Button *button;
    Cell *cell;
    
    CustomButton(int X, int Y, int W, int H, Cell *c): button{new Fl_Button(X, Y, W, H)}, cell{c};
     
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
    
    void generation_table();

    private:
    void quit () { hide(); }

};
