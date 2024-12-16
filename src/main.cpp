#include <iostream>
#include <vec/vec2d.h>
#include <table/table.h>
#include <table/bombs.h>
#include <front_table/game_grid.h>
using namespace std;


int main()
{
    Table table;
    GameGrid grid(table);
    grid.menu();

    return Fl::run();
}