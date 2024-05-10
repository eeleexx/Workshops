///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program that reads information about company employees (name, position, salary) 
/// from a text file and increases the salary of each employee by 10%, writing the updated 
/// information to a new file.
/// Write two functions: for txt and csv file.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void processTxtFile(const std::string& inputFilePath, const std::string& outputFilePath);
void processCsvFile(const std::string& inputFilePath, const std::string& outputFilePath);

int main() {
    processTxtFile("input.txt", "output_updated.txt");
    processCsvFile("input.csv", "output_updated.csv");
    return 0;
}

void processTxtFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    std::ofstream outputFile(outputFilePath);
    if (!outputFile) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string name, position;
        double salary;
        if (iss >> name >> position >> salary) {
            salary *= 1.1;
            outputFile << name << " " << position << " " << salary << std::endl;
        }
    }
}

void processCsvFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    std::ofstream outputFile(outputFilePath);
    if (!outputFile) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string name, position;
        double salary;
        if (iss >> name >> position >> salary) {
            salary *= 1.1;
            outputFile << name << "," << position << "," << salary << std::endl;
        }
    }
}