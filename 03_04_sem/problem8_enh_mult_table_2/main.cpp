////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 8: "Enhanced Multiplication Table".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Modification of the Problem 7 (Multiplication Table), where a user can
/// repeat a solution multiple times (with using the “do..while” loop).
///
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <iomanip>

int main()
{
    int flag = 1;
    do{

        std::cout << "Enter two numbers in two separate rows: " << "\n";
        std::string input1, input2;

        std::getline(std::cin, input1);

        if (input1.empty()){
            flag = 0;
            break;
        }

        int num1 = std::stoi(input1);
        std::getline(std::cin, input2);
        int num2 = std::stoi(input2);

        for (int i = num1; i <= num2; ++i){
            for (int k = num1; k <= num2; ++k){
                std::cout << std::setw(6) << k << " * " << i << " = " << std::setw(3) << i * k << "   ";
            }
        std::cout << "\n";
        }
    } while (flag = 1);

    return 0;
}
