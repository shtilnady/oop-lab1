#ifndef TOJSON_H
#define TOJSON_H

#include <iostream>

/// \namespace Prog1
/// \brief A namespace for JSON conversion utilities.
namespace Prog1 {

    /// \brief Converts an integer to a string.
    /// \param num The integer to convert.
    /// \return A pointer to the string representation of the integer.
    char* int_to_str(const int num);

    /// \brief Converts an array of integers to a JSON string.
    /// \param arr Pointer to the array of integers.
    /// \param len The length of the array.
    /// \param str Reference to a char pointer where the JSON string will be stored.
    /// \return An integer indicating success (0) or failure (non-zero).
    /// \throws bad_array_new_length When param len is wrong.
    int to_json(const int *arr, const int len, char* &str);

    /// \brief Converts an array of integers to a JSON string with size.
    /// \param arr Pointer to the array of integers.
    /// \param len The length of the array.
    /// \param str Reference to a char pointer where the JSON string will be stored.
    /// \param size Reference to an integer where the size of the JSON string will be stored.
    /// \return An integer indicating success (0) or failure (non-zero).
    /// \throws bad_array_new_length When param len is wrong.
    int to_json(const int *arr, const int len, char* &str, int &size);

    /// \brief Converts an array of integers to a JSON string.
    /// \param arr Pointer to the array of integers.
    /// \param len The length of the array.
    /// \param str Reference to a string where the JSON string will be stored.
    /// \return An integer indicating success (0) or failure (non-zero).
    /// \throws bad_array_new_length When param len is wrong.
    int to_json(const int *arr, const int len, std::string &str);

    /// \brief Converts a JSON string to an array of integers.
    /// \param str The JSON string to convert.
    /// \param len Reference to an integer where the length of the resulting array will be stored.
    /// \return A pointer to the array of integers.
    /// \throws logic_error When string is not in JSON format.
    int* to_array(const char *str, int &len);

    /// \brief Converts a JSON string to an array of integers with a specified size.
    /// \param str The JSON string to convert.
    /// \param size The size of the array to allocate.
    /// \param len Reference to an integer where the length of the resulting array will be stored.
    /// \return A pointer to the array of integers.
    /// \throws logic_error When string is not in JSON format.
    int* to_array(const char *str, const int size, int &len);

    /// \brief Converts a JSON string to an array of integers.
    /// \param str The JSON string to convert.
    /// \param len Reference to an integer where the length of the resulting array will be stored.
    /// \return A pointer to the array of integers.
    /// \throws logic_error When string is not in JSON format.
    int* to_array(const std::string str, int &len);
}

#endif
