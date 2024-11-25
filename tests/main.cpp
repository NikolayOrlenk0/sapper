//
// Created by Иван Вязметинов on 25.11.24.
//
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <table/table.h>
#include <table/bombs.h>
using namespace std;


void run_tests() {
    // Тест 1: Простая таблица 3x3 с координатами внутри диапазона
    {
        int size = 3;
        Table t(size);
        vector<Vec2d> coordinates = {{0, 0}, {1, 1}, {2, 2}};
        Bombs bombs;
        bombs.bombs_kord = coordinates;

        int expected = 3; // Укажите ожидаемый результат
        for(auto i : bombs.bombs_kord){
            t.fill_table(i);
        }
        int result = t.size();
        if (result != expected) {
            throw runtime_error("Test 1 Failed: Expected " + to_string(expected) + ", but got " + to_string(result));
        }
    }

    // Тест 2: Таблица 5x5 с непересекающимися координатами
    {
        int size = 5;
        vector<pair<int, int>> coordinates = {{0, 1}, {2, 3}, {4, 4}};
        int expected = 3; // Укажите ожидаемый результат
        int result = solve(size, coordinates);
        if (result != expected) {
            throw runtime_error("Test 2 Failed: Expected " + to_string(expected) + ", but got " + to_string(result));
        }
    }

    // Тест 3: Таблица 4x4 с повторяющимися координатами
    {
        int size = 4;
        vector<pair<int, int>> coordinates = {{0, 0}, {0, 0}, {3, 3}};
        int expected = 2; // Укажите ожидаемый результат
        int result = solve(size, coordinates);
        if (result != expected) {
            throw runtime_error("Test 3 Failed: Expected " + to_string(expected) + ", but got " + to_string(result));
        }
    }

    // Тест 4: Таблица 6x6, пустой список координат
    {
        int size = 6;
        vector<pair<int, int>> coordinates = {};
        int expected = 0; // Укажите ожидаемый результат
        int result = solve(size, coordinates);
        if (result != expected) {
            throw runtime_error("Test 4 Failed: Expected " + to_string(expected) + ", but got " + to_string(result));
        }
    }

    // Тест 5: Таблица 7x7 с максимальным количеством координат
    {
        int size = 7;
        vector<pair<int, int>> coordinates = {
                {0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}
        };
        int expected = 7; // Укажите ожидаемый результат
        int result = solve(size, coordinates);
        if (result != expected) {
            throw runtime_error("Test 5 Failed: Expected " + to_string(expected) + ", but got " + to_string(result));
        }
    }

    cout << "All tests passed successfully!" << endl;
}


int main() {
    try {
        run_tests();
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}