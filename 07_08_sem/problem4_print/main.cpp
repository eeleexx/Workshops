///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Print Data
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write overloaded functions `void print(int)` and `void print(double)` that
/// print an integer and a double, respectively.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

void print(int f) {
    std::cout << f << "\n";
}

void print(double f) {
    std::cout << f << "\n";
}

int main()
{
    int k;
    double n;

    std::cin >> k >> n;

    print(k);
    print(n);

    return 0;
}
