#ifndef FILEREADER_H
#define FILEREADER_H

#include "stdafx.h"

class FileReader {
public:

    FileReader(const std::string& filename);
    std::vector<char> fileReaderMethod();

private:
    std::string filename;
};

#endif 

