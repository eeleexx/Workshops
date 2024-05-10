///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Read a single integer n from the file. In another file, write a matrix filled 
/// in the following way:
/// 1   2   3   4
/// 12  13  14  5
/// 11  16  15  6
/// 10  9   8   7
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

void countFileStatistics(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    int n;
    inputFile >> n;

    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    int count = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i % 2 == 0) {
                outputFile << count++ << "\t";
            } else {
                outputFile << n * (i % 2) + n - j << "\t";
            }
        }
        outputFile << std::endl;
    }
}

int main() {
    countFileStatistics("file.txt");
    return 0;
}