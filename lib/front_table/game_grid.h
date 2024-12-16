#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <Fl/Fl_PNG_Image.H>
#include <vector>
#include <vec/vec2d.h>
#include <string>
#include <table/table.h>
#include <ctime>
#include <FL/Fl_Repeat_Button.H>
#include <iostream>
#include <sstream>
#include <table/settings.h>

const int CELL_SIZE = 40;
const int INDENT = 30;


struct GameGrid
{
    public:

    GameGrid(Table tab): table(tab) {}

    Table table;
    void menu();


    private:
    bool is_game_start = false;
    Settings settings;
    std::vector<std::vector<Fl_Button*>> grid{settings.GRID_HEIGHT, std::vector<Fl_Button*>(settings.GRID_WIDTH)};
    int count_flags = settings.COUNT_OF_BOMBS;
    time_t startTime;  
    Fl_Output* flagCounter;
    Fl_Output* timerOutput;
    Fl_Window* window;


    static void cb_start(Fl_Widget* button, void *data);
    static void cb_cell(Fl_Widget* button, void *data);
    static void timer_callback(void* data);

    void update_timer();
    void flag_counter();
    void start_game();
    void reset_game(std::string text);
    void draw_grid();

    void toggle_flag(Fl_Button* button);
    void open_cells(Fl_Button* button);
    void loose(){reset_game("You loose");};
    void win(){reset_game("You win");};
    void check_win();

    Vec2d search_coords(Fl_Button *button);
    const char* found_lable(int num);
};
