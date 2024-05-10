///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Create a function that copies the content of one file to another file.
///
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

void copyFile(const std::string& sourceFilePath, const std::string& destinationFilePath) {
    std::ifstream inputFile(sourceFilePath);
    std::ofstream outputFile(destinationFilePath);

    outputFile << inputFile.rdbuf();

    inputFile.close();
    outputFile.close();
}



int main() {
    copyFile("source.txt", "destination.txt");
    return 0;
}
