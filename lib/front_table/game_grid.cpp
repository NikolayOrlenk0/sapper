#include "game_grid.h"


Vec2d GameGrid::search_coords(Fl_Button *button)
{
    return Vec2d((button->y() - INDENT)/CELL_SIZE, (button->x() - INDENT)/CELL_SIZE );
}

void GameGrid::check_win()
{
    std::cout << "Check" << std::endl;
    std::cout << this->table.check_win() << std::endl;
    if (this->table.check_win())
        {
            this->win();
        }
}

void GameGrid::cb_cell(Fl_Widget *button, void *data)
{   
    GameGrid *ptr = static_cast<GameGrid*>(data);
    if (ptr->first_check == false)
    {
        ptr->table.regeneration_table(ptr->search_coords(static_cast<Fl_Button*>(button)));
        ptr->first_check = true;
    }
    if (Fl::event_button() == FL_RIGHT_MOUSE)
        ptr->toggle_flag(static_cast<Fl_Button*>(button));

    if (Fl::event_button() == FL_LEFT_MOUSE)
        ptr->open_cells(static_cast<Fl_Button*>(button));
}

void GameGrid::toggle_flag(Fl_Button* button)
{
    Vec2d coord = search_coords(button);
    if (count_flags > 0 && table.is_flag(coord) == false)
    {
        --count_flags;
        button->label("F");
        table.toggle_flag(coord);
        this->change_count_flags();
        std::cout << count_flags << std::endl;
        if (count_flags == 0)
        {
            this->check_win();
        }
        return;
    }

    if (table.is_flag(coord) == true)
    {
        ++count_flags;
        button->label("");
        table.toggle_flag(coord);
        this->change_count_flags();
        return;
    }
}

const char* GameGrid::found_lable(int num)
{
    switch(num)
    {
        case 0: return " ";
        case 1: return "1";
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";
        case 6: return "6";
        case 7: return "7";
        case 8: return "8";
        case 9: return "9";   
        default : return "-2";
    }

}

void GameGrid::open_cells(Fl_Button* button)
{
    Vec2d coord = search_coords(button);
    if (table.is_flag(coord) == false)
    {
        if (table.is_mine(coord) == false)
        {
            std::set<std::pair<int, int>> to_open = table.open_cells(coord);
            for (auto& itr: to_open)
            {
                grid[itr.second][itr.first] -> label(found_lable(table.adjacent_mines(Vec2d(itr.first, itr.second))));
                grid[itr.second][itr.first] -> deactivate();
                table.is_revealed(Vec2d(itr.first, itr.second));
            }
        }
        else
            this->loose();
    }
}

void GameGrid::draw_grid()
{
    for (int i = 0; i < settings.GRID_HEIGHT; ++i)
        for (int j = 0; j < settings.GRID_WIDTH; ++j)
        {
            grid[i][j] = new Fl_Button(INDENT + i*CELL_SIZE, INDENT + j*CELL_SIZE, CELL_SIZE, CELL_SIZE, "");
            grid[i][j] -> callback(cb_cell, this);
            grid[i][j] -> show();
        }

}

void GameGrid::timer_callback(void* data) 
{
    GameGrid* ptr = static_cast<GameGrid*>(data);
    ptr->update_timer();
    Fl::repeat_timeout(1.0, timer_callback, data);
}

void GameGrid::update_timer() 
{
    if (!(this -> is_game_start)) return;
    this->timerOutput->textsize(24);
    time_t currentTime = time(nullptr);
    int elapsed = static_cast<int>(currentTime - startTime);

    int minutes = elapsed / 60;
    int seconds = elapsed % 60;

    std::stringstream timeStr;
    timeStr << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds;

    this->timerOutput->value(timeStr.str().c_str());
    this->window->redraw();
}

void GameGrid::reset_game(std::string text)
{
    this->window->hide();
    this->is_game_start = false;
    this->first_check = false;
    delete this->window;
    this->window = new Fl_Window(200,200);
    Fl_Button *restart = new Fl_Button(50, 125, 100, 50, "Restart");
    if (text == "You loose")
    {
        Fl_Box *box = new Fl_Box(50, 75, 100, 50, "You loose");
    }
    else 
    {
        Fl_Box *box = new Fl_Box(50, 75, 100, 50, "You GOAT");
    }
    restart->callback(cb_start, this);
    this->window->end();
    this->window->show();
}

void GameGrid::change_count_flags()
{
    this->flagCounter->value(std::to_string(this->count_flags).c_str());
    this->flagCounter->textsize(24);
}
void GameGrid::start_game()
{
    this->is_game_start = true;
    this->count_flags = settings.COUNT_OF_BOMBS;
    this->startTime = time(nullptr);
    
    this->window = new Fl_Window(1000, 700, "MineSweeper");
    this->draw_grid();

    this->timerOutput = new Fl_Output(700, 30, 100, 30, "Timer");
    this->timer_callback(this);

    this->flagCounter = new Fl_Output(700, 80, 100, 30, "Flags");
    this->change_count_flags();
    
    this->window->end();
    this->window->show();
}

void GameGrid::cb_start(Fl_Widget* button, void *data)
{
    GameGrid* ptr = static_cast<GameGrid*>(data);
    ptr->window->hide();
    delete ptr->window;
    ptr->window = nullptr;
    ptr->start_game();
}

void GameGrid::menu()
{
    this->window = new Fl_Window(400,400, "Menu");
    Fl_Button *button = new Fl_Button(150,175,100,50, "Play"); 
    button->callback(cb_start, this);
    this->window->end();
    this->window->show();
}