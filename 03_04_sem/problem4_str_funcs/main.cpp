////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 4: "Some functions for dealing with strings".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Try to use functions for dealing with strings:
/// 1) strcmp, strlen for c-strings;
/// 2) string:: size(), length(), operator<, operator+, operator= etc for
///    std::string-s.
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    char str1[255];
    char str2[255];
    std::cout << "Enter two C-strings in two separate lines" << '\n';
    std::cin.getline(str1,  255);
    std::cin.getline(str2,  255);

    if (std::strcmp(str1, str2) != 0) {
        std::cout << "nah" << '\n'; 
    } else {
        std::cout << "yipee" << '\n';
    }
    
    if (std::strlen(str1) == std::strlen(str2)) {
        std::cout << "brah" << '\n';
    } else {
        std::cout << "RAAAAAAAARGH" << '\n';
    }

    std::string str3;
    std::string str4;
    std::cout << "Enter two C++ std::string's (NO VIRUS)" << '\n';
    std::getline(std::cin, str3);
    std::getline(std::cin, str4);

    if (str3.size() == str4.size()) {
        std::cout << "same memory consumption" << '\n';
    } else {
        std::cout << "2 + 2 = 5" << '\n';
    }
    
    std::string combo = str3 + str4 + "MC";
    std::cout << combo << '\n';
    
    if (str3.length() == str4.length()) {
        std::cout << "same length" << '\n';
    } else {
        std::cout << "lmao" << '\n';
    }

    if (str3 < str4) {
        std::cout << "the 1st string comes before 2nd lexicographically" << '\n';
    } else {
        std::cout << "the 2nd string comes before 1st lexicographically" << '\n';
    }

    return 0;
}
