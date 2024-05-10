///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Sum digits
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes a number and
/// find sum of digits recursively.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int RecSum(int num) {
    if (num == 0) {
        return 0;
    }

    int lastdigit, remain, sum;
    lastdigit = num % 10;
    remain = num / 10;
    sum = RecSum(remain);
    return lastdigit + sum;
}

int main()
{
    int num;

    std::cin >> num;

    std::cout << RecSum(num) << "\n";

    return 0;
}
