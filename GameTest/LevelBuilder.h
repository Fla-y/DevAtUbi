#ifndef LEVELBUILDER_H
#define LEVELBUILDER_H

#include "stdafx.h"

class LevelBuilder {
public:
    LevelBuilder();
    void LoadLevel(const std::string& filePath);
    void RenderLevel();

private:
    void ParseLevelData(const std::vector<char>& levelData);
    std::vector<std::string> levelFilePaths; 
    int currentLevelIndex;
};

#endif 

