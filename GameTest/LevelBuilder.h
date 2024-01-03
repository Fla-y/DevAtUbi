#ifndef LEVELBUILDER_H
#define LEVELBUILDER_H

#include "stdafx.h"

class LevelBuilder {
public:
    LevelBuilder();
    void LoadLevel(const std::string& filePath);
    void UpdateLevel(float deltaTime); // If needed for dynamic elements
    void RenderLevel();
    bool NeedToLoadNextLevel() const;

private:
    void ParseLevelData(const std::vector<char>& levelData);
    std::vector<std::string> levelFilePaths; // Paths to level files
    int currentLevelIndex;
};

#endif 

