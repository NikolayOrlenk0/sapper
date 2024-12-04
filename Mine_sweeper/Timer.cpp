#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Repeat_Button.H>
#include <ctime>
#include <iostream>
#include <sstream>

#define FIELD_SIZE 10  // Размер поля (например, 10x10)

class MineSweeperWindow : public Fl_Window {
private:
    Fl_Output* flagCounter;  // Счетчик флагов
    Fl_Output* timerOutput;  // Таймер
    int flagCount;           // Количество оставшихся флагов
    time_t startTime;        // Время начала
    bool gameStarted;        // Флаг начала игры

public:
    MineSweeperWindow(int w, int h, const char* title) 
        : Fl_Window(w, h, title), flagCount(25), gameStarted(false) {
        flagCounter = new Fl_Output(10, 10, 100, 30, "Flags left");
        flagCounter->textsize(24);
        updateFlagCounter();

        timerOutput = new Fl_Output(200, 10, 100, 30, "Timer");
        timerOutput->textsize(24);
        timerOutput->value("00:00");

        // Инициализируем игровое поле (сетку)
        for (int y = 0; y < FIELD_SIZE; ++y) {
            for (int x = 0; x < FIELD_SIZE; ++x) {
                Fl_Button* cell = new Fl_Button(50 + x * 30, 50 + y * 30, 30, 30);
                cell->callback(cell_callback, this);
            }
        }
    }

    // Функция обновления счетчика флагов
    void updateFlagCounter() {
        std::stringstream ss;
        ss << flagCount;
        flagCounter->value(ss.str().c_str());
    }

    // Функция обновления таймера
    void updateTimer() {
        if (!gameStarted) return;

        time_t currentTime = time(nullptr);
        int elapsed = static_cast<int>(currentTime - startTime);

        int minutes = elapsed / 60;
        int seconds = elapsed % 60;

        std::stringstream timeStr;
        timeStr << (minutes < 10 ? "0" : "") << minutes << ":"
                << (seconds < 10 ? "0" : "") << seconds;

        timerOutput->value(timeStr.str().c_str());
        redraw();
    }

    // Обработчик таймера
    static void timer_callback(void* data) {
        MineSweeperWindow* window = static_cast<MineSweeperWindow*>(data);
        window->updateTimer();
        Fl::repeat_timeout(1.0, timer_callback, data);
    }

    // Функция для старта игры
    void startGame() {
        startTime = time(nullptr);  // Засекаем время начала игры
        gameStarted = true;
        Fl::add_timeout(1.0, timer_callback, this);  // Запускаем таймер
    }

    // Обработчик нажатия на клетку (ПКМ для флага)
    static void cell_callback(Fl_Widget* widget, void* data) {
        MineSweeperWindow* window = static_cast<MineSweeperWindow*>(data);

        // Проверяем, является ли нажатие правой кнопкой мыши
        if (Fl::event_button() == FL_RIGHT_MOUSE) {
            if (window->flagCount > 0) {
                window->flagCount--;  // Уменьшаем количество флагов
                window->updateFlagCounter();  // Обновляем счетчик
            }
        }
    }

    // Запуск игры
    void start() {
        startGame();
        this->show();
    }
};

int main() {
    MineSweeperWindow window(400, 400, "Mine Sweeper");
    window.start();  // Запуск игры
    return Fl::run();  // Главный цикл FLTK
}