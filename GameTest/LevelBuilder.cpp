#include "stdafx.h"
#include "LevelBuilder.h"
#include "app\app.h"
#include "FileReader.h" 

LevelBuilder::LevelBuilder() : currentLevelIndex(0) {
    levelFilePaths = { "level1.txt", "level2.txt", "level3.txt" };
}

void LevelBuilder::LoadLevel(const std::string& filePath) {
    FileReader levelFile(filePath);
    std::vector<char> fileContents = levelFile.fileReaderMethod();
    ParseLevelData(fileContents);
}

void LevelBuilder::ParseLevelData(const std::vector<char>& levelData) {
    for (char c : levelData) {
        if (c == '1') {
        }
        else if (c == '2') {
        }
        else if (c == '3') {
        }
        else if (c == '@') {
        }
    }
}

void LevelBuilder::RenderLevel() {
}
