///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program to read the content of a text file and write its content in reverse order to another file.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>

void reverseFileContent(const std::string& inputFilePath, const std::string& outputFilePath) {
     std::ifstream inputFile(inputFilePath);
     std::string content((std::istreambuf_iterator<char>(inputFile)),
                         std::istreambuf_iterator<char>());
    
    inputFile.close();
    
    std::reverse(content.begin(), content.end());
    
    std::ofstream outputFile(outputFilePath);
    
    outputFile << content;
    
    outputFile.close();
}

int main() {
    reverseFileContent("input.txt", "output_reversed.txt");
    return 0;
}
