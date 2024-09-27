#include <iostream>
#include <limits>
#include "tojson.h"
#include "check.h"

using namespace Prog1;

int main () {
    int len = 0;
    int size = 0;
    int &sizelink = size;
    int &lenlink = len;
    int *array = nullptr;
    char *str = nullptr;
    char* &strlink = str;
    std::string strcpp;
    std::string &strcpplink = strcpp;
    int flag = 1;
    int com = 0;
    while (flag == 1) {
        std::cout << "(0) Из массива в строку." << std::endl;
        std::cout << "(1) Из строки в массив." << std::endl;
        try {
        com = getInt();
            if (com == 0) {
                array = arrayinput(&len);
                to_json(array, len, strcpplink);
                std::cout << "Перегрузка std::string" << std::endl;
                std::cout << strcpp << std::endl;
                to_json(array, len, strlink);
                std::cout << "Перегрузка const char*" << std::endl;
                std::cout << str << std::endl;
                delete[] str;
                to_json(array, len, strlink, sizelink);
                std::cout << "Перегрузка const char* + size_t" << std::endl;
                std::cout << str << std::endl << std::endl;
            }
            else if (com == 1) {
                strcpp = jsoninput();
                array = to_array(strcpp, lenlink);
                std::cout << "Перегрузка std::string" << std::endl;
                for (int i = 0; i < len; i++) {
                    std::cout << "arr[" << i << "] = " << array[i] << std::endl;
                }
                delete[] array;
                size = strcpp.length();
                str = new char[size + 1];
                str[size] = 0;
                std::copy(strcpp.data(), strcpp.data() + size, str);
                array = to_array(str, lenlink);
                std::cout << "Перегрузка const char*" << std::endl;
                for (int i = 0; i < len; i++) {
                    std::cout << "arr[" << i << "] = " << array[i] << std::endl;
                }
                delete[] str;
                delete[] array;
                str = new char[size];
                std::copy(strcpp.data(), strcpp.data() + size, str);
                array = to_array(str, size, lenlink);
                std::cout << "Перегрузка const char* + size_t" << std::endl;
                for (int i = 0; i < len; i++) {
                    std::cout << "arr[" << i << "] = " << array[i] << std::endl;
                }
                std::cout << std::endl;
            }
            else {
                std::cout << "Нет такой команды." << std::endl;
            }
        }
        catch (const std::invalid_argument e) {
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch (const std::bad_array_new_length e) {
            std::cout << "Размер массива должен быть положительный." << std::endl;
        }
        catch (const std::runtime_error e) {
            std::cout << e.what() << std::endl;
            flag = 0;
        }
        delete[] array;
        array = nullptr;
        delete[] str;
        str = nullptr;
    }
    return 0;
}