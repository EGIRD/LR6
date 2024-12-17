#include "Task_1.h"
#include <iostream>
#include <limits>

void Task_1() {
    int round_open  = 0, round_close  = 0, count;
    int square_open = 0, square_close = 0;
    int curly_open  = 0, curly_close  = 0;
    int trian_open  = 0, trian_close  = 0;
    const int SIZE = 81;
    char string[SIZE],ch;

    std::cout << "Вы выбрали задание 1\nВведите строку:\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while((ch = getchar()) != '\n')
        switch(ch){
            case '(': round_open++;
            break;
            case ')': round_close++;
            break;
            case '[': square_open++;
            break;
            case ']': square_close++;
            break;
            case '{': curly_open++;
            break;
            case '}': curly_close++;
            break;
            case '<': trian_open++;
            break;
            case '>': trian_close++;
        }

    count = round_open + round_close + square_open + square_close + curly_open + curly_close + trian_open + trian_close;

    if(!count)
        std::cout << "Cкобки отсутствуют\n";
    else {
        std::cout << "Количество:";
        if(round_open > 0)
            std::cout << "\nНачальных круглых - " << round_open  << "\nЗакрытых круглых - " << round_close;

        if (square_open > 0)
            std::cout << "\nНачальных квадратных - " << square_open  << "\nЗакрытых квадратных - " << square_close;

        if (curly_open > 0)
            std::cout << "\nНачальных фигурных - " << curly_open  << "\nЗакрытых фигурных - " << curly_close;

        if(trian_open > 0)
            std::cout << "\nНачальных треугольных - "  << trian_open  << "\nЗакрытых треугольных - " << trian_close << std::endl;
        std::cout << "\nОбщее количество скобок - " << count << std::endl;
    }
}