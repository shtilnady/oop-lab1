#ifndef CHECK_H
#define CHECK_H

#include <string>

/// \namespace Prog1
/// \brief A namespace for input handling functions.
namespace Prog1 {

    /// \brief Retrieves an integer input from the user.
    ///
    /// This function prompts the user for an integer input and returns the value entered.
    ///
    /// \return The integer value input by the user.
    /// \throws runtime_error In case when user want to finish program.
    /// \throws invalid_argument In case when user input not integer.
    int getInt();

    /// \brief Accepts an array input from the user.
    ///
    /// This function prompts the user to input a series of integers, storing the count
    /// of integers in the provided length pointer. The function dynamically allocates
    /// memory for the array of integers, which must be freed by the caller.
    ///
    /// \param len Pointer to an integer where the length of the input array will be stored.
    /// \return A pointer to the dynamically allocated array of integers.
    /// \throws runtime_error In case when user want to finish program.
    /// \throws invalid_argument In case when user input not integer.
    int* arrayinput(int *len);

    /// \brief Accepts a JSON string input from the user.
    ///
    /// This function prompts the user to enter a JSON formatted string and returns it
    /// as a std::string object.
    ///
    /// \return The JSON string input by the user.
    /// \throws runtime_error In case when user want to finish program.
    std::string jsoninput();
}

#endif