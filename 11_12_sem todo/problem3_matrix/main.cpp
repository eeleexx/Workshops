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
/// 8   7   6   5
/// 9   10  11  12
/// 16  15  14  13
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
            outputFile << ((i % 2 == 0) ? count++ : n * (i % 2) + j + 1 - i % 2) << "\t";
        }
        outputFile << std::endl;
    }
}

int main() {
    countFileStatistics("file.txt");
    return 0;
}