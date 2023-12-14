#include "stdafx.h"
#include "FileReader.h"
#include <iostream>
#include <fstream>

//costructor
FileReader::FileReader(const std::string& filename) : filename(filename) {}


std::vector<char> FileReader::fileReaderMethod() {
    std::vector<char> fileContents;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    // Read the file character by character
    char c;
    while (file.get(c)) {
        fileContents.push_back(c);
    }
    file.close();

    return fileContents;
}
