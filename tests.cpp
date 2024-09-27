#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "tojson.h"
#include <string>

using namespace Prog1;

TEST_CASE("lab1") {
    SECTION("int_to_str") {
        char *str = int_to_str(12345);
        REQUIRE(strcmp(str, "12345") == 0);
        delete[] str;
        str = int_to_str(-327);
        REQUIRE(strcmp(str, "-327") == 0);
        delete[] str;
        str = int_to_str(0);
        REQUIRE(strcmp(str, "0") == 0);
        delete[] str;
    }

    SECTION("to_json") {
        int len = 5;
        int *arr = new int[len] {-2352, 0, 1233, 8888, -12456976};
        char* str = nullptr;
        int size;
        char* &link = str;
        to_json(arr, len, link);
        REQUIRE(strcmp(str, "[-2352,0,1233,8888,-12456976]") == 0);
        delete[] str;
        to_json(arr, len, str, size);
        REQUIRE(strcmp(str, "[-2352,0,1233,8888,-12456976]") == 0);
        REQUIRE(size == strlen("[-2352,0,1233,8888,-12456976]"));
        delete[] str;
        std::string string;
        to_json(arr, len, string);
        REQUIRE(string == "[-2352,0,1233,8888,-12456976]");
        delete[] arr;

        len = 1;
        arr = new int[len] {546};
        to_json(arr, len, link);
        REQUIRE(strcmp(str, "[546]") == 0);
        delete[] str;
        to_json(arr, len, str, size);
        REQUIRE(strcmp(str, "[546]") == 0);
        REQUIRE(size == strlen("[546]"));
        delete[] str;
        to_json(arr, len, string);
        REQUIRE(string == "[546]");

        REQUIRE_THROWS(to_json(arr, -5, link));
        delete[] arr;
    }

    SECTION("to_array") {
        std::string str = "[142,4560,0,-52]";
        int len = 0;
        int &link = len;
        int *arr = to_array(str, link);
        REQUIRE(len == 4);
        REQUIRE(arr[0] == 142);
        REQUIRE(arr[1] == 4560);
        REQUIRE(arr[2] == 0);
        REQUIRE(arr[3] == -52);
        delete[] arr;

        arr = to_array(str.data(), link);
        REQUIRE(len == 4);
        REQUIRE(arr[0] == 142);
        REQUIRE(arr[1] == 4560);
        REQUIRE(arr[2] == 0);
        REQUIRE(arr[3] == -52);
        delete[] arr;

        arr = to_array(str.data(), str.length(), link);
        REQUIRE(len == 4);
        REQUIRE(arr[0] == 142);
        REQUIRE(arr[1] == 4560);
        REQUIRE(arr[2] == 0);
        REQUIRE(arr[3] == -52);
        delete[] arr;

        str = "[]";
        REQUIRE_THROWS(to_array(str, link));
        REQUIRE_THROWS(to_array(str.data(), link));
        REQUIRE_THROWS(to_array(str.data(), str.length(), link));

        str = "[34,]";
        REQUIRE_THROWS(to_array(str, link));
        REQUIRE_THROWS(to_array(str.data(), link));
        REQUIRE_THROWS(to_array(str.data(), str.length(), link));

        str = "23, 532]";
        REQUIRE_THROWS(to_array(str, link));
        REQUIRE_THROWS(to_array(str.data(), link));
        REQUIRE_THROWS(to_array(str.data(), str.length(), link));

        str = "[23,a,-54]";
        REQUIRE_THROWS(to_array(str, link));
        REQUIRE_THROWS(to_array(str.data(), link));
        REQUIRE_THROWS(to_array(str.data(), str.length(), link));

        str = "[-43,23-0, 3]";
        REQUIRE_THROWS(to_array(str, link));
        REQUIRE_THROWS(to_array(str.data(), link));
        REQUIRE_THROWS(to_array(str.data(), str.length(), link));
    }
}