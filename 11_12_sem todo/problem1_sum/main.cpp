///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       14.02.2024
///
/// TASK DESCRIPTION
///
/// Write a function to read a file containing integers 
/// separated by spaces or newlines, sum these integers, 
/// and write the result to another file.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

int sumIntegersInFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    if (!inputFile) {
        throw std::runtime_error("Failed to open input file");
    }

    std::vector<int> integers;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            integers.push_back(num);
        }
    }

    int sum = 0;
    for (int num : integers) {
        sum += num;
    }

    std::ofstream outputFile(outputFilePath);
    if (!outputFile) {
        throw std::runtime_error("Failed to open output file");
    }

    outputFile << sum;

    return 0;
}

int main() {
    try {
        sumIntegersInFile("input.txt", "output.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}