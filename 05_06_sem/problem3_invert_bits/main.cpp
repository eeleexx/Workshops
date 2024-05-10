///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Bit Manipulation - Bitwise Complement
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes an integer n as input and performs bitwise complement
/// (inverts all bits) on it. Print the resulting number in binary and decimal forms.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int complement = ~n;

    for (int i = sizeof(int) * 8 - 1; i >= 0; --i) {
            int bit = (complement >> i) & 1;
            std::cout << bit;
    }

    std::cout << "\n" << complement;
    return 0;
}
