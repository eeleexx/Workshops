///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Sum of Numbers
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a variadic function `int sum(int count, ...)` that returns the sum of 
/// 'count' numbers.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdarg>

int sum(int count, ...) {
    int total = 0;
    va_list args;

    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        total += va_arg(args, int);
    }
    va_end(args);

    return total;
}

int main() {

    std::cout << sum(3, 1, 2, 3) << "\n";
    std::cout << sum(5, 5, 10, 15, 20, 25) << "\n";

    return 0;
}