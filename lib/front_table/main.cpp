
#include "grid.cpp"

int main() {  
    GameLogic logic(10, 10, 20);
    GameWindow window(600, 400, "Sapper Game"); 
    window.show(); 
    return Fl::run(); 
}