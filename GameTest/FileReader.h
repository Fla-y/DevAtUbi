#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>

class FileReader {
public:
    // Constructor takes filename as an argument
    FileReader(const std::string& filename);

    // Function to read the file and return a vector of characters
    std::vector<char> fileReaderMethod();

private:
    std::string filename;
};

#endif 

