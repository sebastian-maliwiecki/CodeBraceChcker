#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>

// Function to read a file and store each line in a vector of strings
std::vector<std::string> readFileToVector(const std::string& fileName) {
    std::vector<std::string> lines;
    std::ifstream file(fileName);
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return lines;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}

// Function to check if a string contains a specific curly brace ("{" or "}")
bool checkCurly(const std::string& lineOfCode, const std::string& curly)
{
    return lineOfCode.find(curly) != std::string::npos;
}

// Function to check if a string contains both opening and closing braces
bool hasBothBraces(const std::string& str) {
    return str.find('{') != std::string::npos && str.find('}') != std::string::npos;
}

// Function to check the block structure of the code and output matching braces
void checkBlocks(const std::vector<std::string>& code, std::vector<int>& stackOfBlocks) {
    for (std::size_t index = 0; index < code.size(); ++index) {
        if (hasBothBraces(code[index])) {
            continue; // Skip lines that have both braces
        }

        if (checkCurly(code[index], "{")) {
            stackOfBlocks.push_back(index);
        } else if (checkCurly(code[index], "}")) {
            if (!stackOfBlocks.empty()) {
                std::cout << stackOfBlocks.back() << " -> " << index << "\n";
                stackOfBlocks.pop_back();
            } else {
                std::cerr << "Unmatched closing brace at line " << index << "\n";
            }
        }
    }

    while (!stackOfBlocks.empty()) {
        std::cerr << "Unmatched opening brace at line " << stackOfBlocks.back() << "\n";
        stackOfBlocks.pop_back();
    }
}

// Main function to read the file, check the code for matching braces, and output the results
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    const std::string fileName = argv[1];
    std::vector<std::string> code = readFileToVector(fileName);

    if (code.empty()) {
        std::cerr << "Error: No code to process." << std::endl;
        return 1;
    }

    std::vector<int> stackOfBlocks;
    checkBlocks(code, stackOfBlocks);

    return 0;
}