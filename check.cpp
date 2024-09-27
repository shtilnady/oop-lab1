#include <iostream>
#include "check.h"
#include <string>

namespace Prog1 {

    #define PROMPT ">"

    int getInt() {
        int num;
        std::cin >> num;
        if (std::cin.eof()) {
            throw std::runtime_error("Завершение программы.");
        }
        else if (!std::cin.good()) {
            throw std::invalid_argument("Некорректный ввод.");
        }
        return num;
    }

    int* arrayinput(int *len) {
        std::cout << "Введите размер массива: ";
        *len = getInt();
        int* array = new int[*len];
        int num;
        for (int i = 0; i < *len; i++) {
            std::cout << "Введите число [" << i << "]: ";
            try {
                num = getInt();
            }
            catch (...) {
                delete[] array;
                throw;
            }
            array[i] = num;
        }
        return array;
    }

    std::string jsoninput() {
        std::string str;
        std::cout << PROMPT;
        std::cin >> str;
        if (std::cin.eof()) {
            throw std::runtime_error("Завершение программы.");
        }
        return str;
    }

}