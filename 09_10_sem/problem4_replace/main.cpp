///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function to find and replace all occurrences of a word in a file.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>

void findAndReplaceInFile(const std::string& filePath, const std::string& toFind, const std::string& toReplace) {
    std::ifstream file(filePath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    std::string content = buffer.str();
    std::size_t pos = content.find(toFind);

    while (pos != std::string::npos) {
        content.replace(pos, toFind.length(), toReplace);
        pos = content.find(toFind, pos + toReplace.length());
    }

    std::ofstream outputFile(filePath);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open file for writing: " << filePath << std::endl;
        return;
    }

    outputFile << content;
    outputFile.close();
}


int main() {
    findAndReplaceInFile("file.txt", "oldWord", "newWord");
    return 0;
}