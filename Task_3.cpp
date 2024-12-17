#include "Task_3.h"
#include <iostream>
#include <limits>

bool Check(char *, char*);

void Task_3() {
    const int SIZE = 255;
    char* str1 = new char[SIZE];
    char* str2 = new char[SIZE];
    int i;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Вы выбрали задание 3\nВведите первую строку:\n";
    std::cin.getline(str1,SIZE);

    std::cout << "Введите вторую строку:\n";
    std::cin.getline(str2,SIZE);

    if(Check(str1,str2))
        std::cout << "Данные слова вляются анаграммами\n";
    else
        std::cout << "Данные слова не являются анаграммами\n";

    delete[] str1;
    delete[] str2;

    str1 = nullptr;
    str2 = nullptr;
}

bool Check(char* str1, char* str2) {
    int i,j;
    int count[255] = {0};
    for(i = 0; str1[i]; i++)
        count[(unsigned char)str1[i]]++;

    for(j = 0; str2[j]; j++)
        count[(unsigned char)str2[j]]--;

    for(i = 0; i < 255; i++)
        if(count[i] != 0)
            return false;

    return true;
}