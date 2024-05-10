///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program to count the number of lines, words, and characters in a text file.
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <sstream> 
#include <string>

void countFileStatistics(const std::string& filePath) {
    std::ifstream file;

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return;
    }

    int lines = 0, words = 0, characters = 0;
    std::string line;

    while (getline(file, line)) {
        ++lines;
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            ++words;
        }
        characters += line.length() + 1;
    }

    std::cout << "Lines: " << lines << "\nWords: " << words << "\nCharacters (including newlines): " << characters << std::endl;
}



int main() {
    countFileStatistics("file.txt");
    return 0;
}