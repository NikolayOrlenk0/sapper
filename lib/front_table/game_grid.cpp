#include "game_grid.h"


Vec2d GameGrid::search_coords(Fl_Button *button)
{
    return Vec2d((button->x() - INDENT)/CELL_SIZE, (button->y() - INDENT)/CELL_SIZE );
}

void GameGrid::cb_cell(Fl_Widget *button, void *data)
{   
    GameGrid *ptr = static_cast<GameGrid*>(data);

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
    }

    if (table.is_flag(coord) == true)
    {
        ++count_flags;
        button->label("");
        table.toggle_flag(coord);
    }
}

void GameGrid::open_cells(Fl_Button* button)
{
    Vec2d coord = search_coords(button);
    if (table.is_flag(coord) == false)
    {
        if (table.is_mine(coord) == false)
        {
            std::vector<Vec2d> to_open = table.open_cells(coord);
            for (Vec2d itr: to_open)
            {

                grid[itr.x][itr.y] -> label(table.adjacent_mines(coord).c_str());
                grid[itr.x][itr.y] -> deactivate();
                table.is_revealed(coord);
            }
        }
        else 
            this->loose();
    }
}

void GameGrid::draw_grid()
{
    for (int i = 0; i < GRID_HEIGHT; ++i)
        for (int j = 0; j < GRID_WIDTH; ++j)
        {
            grid[i][j] = new Fl_Button(INDENT + i*CELL_SIZE, INDENT + j*CELL_SIZE, CELL_SIZE, CELL_SIZE);
            grid[i][j] -> callback(cb_cell, this);
        }

}

int main()
{

}