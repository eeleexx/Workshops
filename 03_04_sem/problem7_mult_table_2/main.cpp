////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 7: "Multiplication Table".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Program asks a user for two numbers, 1 <= (m, n) <= 8 and prints a rectangle
/// multiplication table aligning output at tab positions.
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Enter two numbers in two separate rows: " << "\n";
    int num1;
    int num2;

    std::cin >> num1;
    std::cin >> num2;

    for (int i = num1; i <= num2; ++i){
        for (int k = num1; k <= num2; ++k){
             std::cout << std::setw(6) << k << " * " << i << " = " << std::setw(3) << i * k << "   ";
        }
    std::cout << "\n";
    }

    return 0;
}
