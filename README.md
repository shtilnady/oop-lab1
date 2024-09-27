This C++ program implements a set of functions for converting an array of integers to json format and back.
An array of integers is passed as input to the function. The function for converting to this text returns a text consisting of the passed numbers, separated by a comma and enclosed in square brackets (json format).
The function for converting from a string must receive the input string representation of the array and return the original array.

For example, the numbers of the array 1,2,3 must be converted to the expression "[1, 2, 3]".

Three overloads of the described functions are implemented:

1. Works with a null-terminated string (const char*).
2. Works with an array of characters and their use (const char* + size_t).
3. Works with an instance of the std::string class.

The program comes with documentation, tests and their coverage. The program is compiled using the Smake auto-build tools. Developed using C++ libraries and algorithms, as well as the absence of memory leaks and the continuation of correct program operation in the event of incorrect user input.
