#include "stdafx.h"
#include "LevelBuilder.h"
#include "app\app.h"
#include "FileReader.h" // Your file reading class

LevelBuilder::LevelBuilder() : currentLevelIndex(0) {
    // Initialize with paths to level files
    levelFilePaths = { "level1.txt", "level2.txt", "level3.txt" }; // and so on
}

void LevelBuilder::LoadLevel(const std::string& filePath) {
    FileReader levelFile(filePath);
    std::vector<char> fileContents = levelFile.fileReaderMethod();
    ParseLevelData(fileContents);
}

void LevelBuilder::ParseLevelData(const std::vector<char>& levelData) {
    // Interpret the characters and construct the level accordingly
    // E.g., '1' for normal ground level, '@' for triggering next level load
    // Translate these characters into game world coordinates or objects
    for (char c : levelData) {
        if (c == '1') {
            // Handle normal ground level placement
        }
        else if (c == '2') {
            // Handle other types of ground or objects
        }
        else if (c == '3') {
            // And so on for other characters
        }
        else if (c == '@') {
            // This character signifies the need to load the next part of the level
            // You might set a flag here to indicate that the next level should be loaded
        }
        // Add more conditions as needed for different characters
    }
}

void LevelBuilder::RenderLevel() {
    // Render the level elements
}

/*
bool LevelBuilder::NeedToLoadNextLevel() const {
    // Determine if the '@' character was encountered and the next level should be loaded
   // return (currentLevelIndex < levelFilePaths.size() - 1)&& /* condition to switch level *;
}*/