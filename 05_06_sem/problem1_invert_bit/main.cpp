///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Bit Manipulation - Toggle Bit
/// \version    0.1.0
/// \date       24.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program that takes an integer n and a position k as input. The program
/// should toggle (invert) the k-th bit of the integer n (i.e., change 0 to 1 and 
/// 1 to 0) and print the resulting number in binary and decimal forms.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int togglebit(int n, int k){
        return (n ^ (1 << (k-1)));
    }

int main()
{
    int a, b;
    std::cout << "Enter an integer and the position of bit to be inverted: ";
    std::cin >> a >> b;
    
    std::cout << togglebit(a, b);

    return 0;
}
