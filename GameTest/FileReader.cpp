#include "stdafx.h"
#include "FileReader.h"


FileReader::FileReader(const std::string& filename) : filename(filename) {
}

std::vector<char> FileReader::fileReaderMethod() {
    std::vector<char> fileContents;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    char c;
    while (file.get(c)) {
        fileContents.push_back(c);
    }
    file.close();

    return fileContents;
}
