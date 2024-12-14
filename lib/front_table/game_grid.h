#pragma once

#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl.H>
#include <Fl/Fl_Widget.H>
#include <Fl/Fl_PNG_Image.H>
#include <vector>
#include <vec/vec2d.h>
#include <string>
#include <table/table.h>

const int CELL_SIZE = 15;
const int GRID_WIDTH = 15;
const int GRID_HEIGHT = 15;
const int COUNT_OF_BOMBS = 25;
const int INDENT = 30;


struct GameGrid
{
    public:
    
    Table table;
    std::vector<std::vector<Fl_Button*>> grid;
    int count_flags = COUNT_OF_BOMBS;


    Vec2d search_coords(Fl_Button *button);
    void draw_grid();
    static void cb_cell(Fl_Widget* button, void *data);
    void toggle_flag(Fl_Button* button);
    void open_cells(Fl_Button* button);
    
};
