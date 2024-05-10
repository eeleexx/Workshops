///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Create program to read data from a CSV file (comma separated) 
/// and calculate the average value in each column. Separate into function
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>

std::vector<std::vector<double>> readCSVData(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        throw std::runtime_error("Failed to open file");
    }

    std::vector<std::vector<double>> data;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<double> row;
        double value;
        while (iss >> value) {
            row.push_back(value);
            if (iss.peek() == ',') {
                iss.ignore();
            }
        }
        data.push_back(row);
    }

    return data;
}

std::vector<double> calculateColumnAverages(const std::vector<std::vector<double>>& data) {
    if (data.empty()) {
        throw std::runtime_error("No data to process");
    }

    size_t numColumns = data[0].size();
    std::vector<double> columnSums(numColumns, 0.0);
    size_t numRows = data.size();

    for (const auto& row : data) {
        for (size_t col = 0; col < numColumns; ++col) {
            columnSums[col] += row[col];
        }
    }

    std::vector<double> averages;
    for (double sum : columnSums) {
        averages.push_back(sum / numRows);
    }

    return averages;
}

int main() {
    try {
        std::string filePath = "data.csv";
        std::vector<std::vector<double>> data = readCSVData(filePath);
        std::vector<double> averages = calculateColumnAverages(data);

        std::cout << "Average values in each column:" << std::endl;
        for (size_t i = 0; i < averages.size(); ++i) {
            std::cout << "Column " << (i + 1) << ": " << averages[i] << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}