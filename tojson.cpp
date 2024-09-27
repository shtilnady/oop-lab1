#include "tojson.h"
#include "check.h"
#include <iostream>
#include <cstring>

namespace Prog1 {

    char* int_to_str(const int num) {
        int digits = 0;
        int numcopy = num;
        if (num <= 0) {
            digits += 1;
            numcopy = -num;
        }
        while (numcopy > 0) {
            digits++;
            numcopy /= 10;
        }
        char *res = new char[digits + 1];
        sprintf(res, "%d", num);
        return res;
    }

    int to_json(const int *arr, const int len, char* &str) {
        if (len <= 0) {
            throw std::bad_array_new_length();
        }
        int initlen = len * 2 + 1;
        str = new char[initlen + 1];
        for (int i = 1; i < initlen + 1; i++) {
            str[i] = 0;
        }
        str[0] = '[';
        char* strnum = nullptr;
        char* newstr = nullptr;
        int curlen = 0;
        for (int i = 0; i < len; i++) {
            strnum = int_to_str(arr[i]);
            curlen = strlen(str);
            if (strlen(strnum) + curlen > initlen - 1) {
                initlen = curlen + strlen(strnum) + 1;
                newstr = new char[initlen + 1];
                std::copy(str, str + curlen, newstr);
                delete[] str;
                str = newstr;
                str[initlen - 1] = 0;
                str[initlen] = 0;
            }
            std::copy(strnum, strnum + strlen(strnum), str + curlen);
            delete[] strnum;
            str[strlen(str)] = ',';
        }
        str[strlen(str) - 1] = ']';
        return 0;
    }

    int to_json(const int *arr, const int len, char* &str, int &initlen) {
        to_json(arr, len, str);
        initlen = strlen(str);
        return 0;
    }

    int to_json(const int *arr, const int len, std::string &str) {
        char *strc = nullptr;
        char* &strlink = strc;
        to_json(arr, len, strlink);
        str = std::string(strc);
        delete[] strc;
        return 0;
    }

    int* to_array(const char *str, const int size, int &len) {
        if (size < 3 || str[0] != '[' || str[size - 1] != ']' || isdigit(str[size - 2]) == 0 || str[1] == ',') {
            throw std::logic_error("Некорректный ввод строки в формате json.");
        }
        for (int i = 1; i < size - 1; i++) {
            if (isdigit(str[i]) > 0 || str[i] == ',') {
                continue;
            }
            else if (str[i] == '-' && (str[i - 1] == ',' || str[i - 1] == '[')) {
                continue;
            }
            else {
                throw std::logic_error("Некорректный ввод строки в формате json.");
            }
        }
        len = 1;
        int *arr = new int[len];
        int *newarr = nullptr;
        int num = 0;
        int start = 1;
        for (int i = 1; i < size - 1; i++) {
            if (str[i] == ',') {
                num = strtol(str + start, NULL, 10);
                start = i + 1;
                arr[len - 1] = num;
                len++;
                newarr = new int[len];
                std::copy(arr, arr + (len - 1), newarr);
                delete[] arr;
                arr = newarr;
            }
        }
        num = strtol(str + start, NULL, 10);
        arr[len - 1] = num;
        return arr;
    }

    int* to_array(const char *str, int &len) {
        int *arr = to_array(str, strlen(str), len);
        return arr;
    }

    int* to_array(const std::string str, int &len) {
        return to_array(str.data(), len);
    }

}