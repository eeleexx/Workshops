///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function to read a file containing integers 
/// separated by spaces or newlines, sum these integers, and write the result to another file.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <fstream>

int sumIntegersInFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);

    int temp, sum = 0;
    while (inputFile >> temp) {
        sum += temp;
    }

    outputFile << sum;

    inputFile.close();
    outputFile.close();

    return 0;
}

int main() {
    
    sumIntegersInFile("input.txt", "output.txt");

    return 0;
}
