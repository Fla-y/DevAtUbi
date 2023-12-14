#include "stdafx.h"
#include "LevelBuilder.h"
#include "app\app.h"


LevelBuilder::LevelBuilder(const std::vector<char>& fileContents) : loadNextLevel(false) {

    level.resize(10, std::vector<int>(fileContents.size(), 0));
    for (size_t i = 0; i < fileContents.size(); ++i) {
        char c = fileContents[i];

        if (c == '1') {
            level.back()[i] = 25;
        }
        else if (c == '@') {
            loadNextLevel = true;
        }
    }
}

void LevelBuilder::BuildLevel(const std::vector<char>& fileContents, const std::vector<std::vector<int>>& levelData) {
    for (size_t i = 0; i < fileContents.size(); ++i) {
        char c = fileContents[i];
        for (size_t j = 0; j < levelData[i].size(); ++j) {
            if (levelData[i][j] == 1) {
                level.back()[i] = 25;
            }
            else if (c == '@') {
                loadNextLevel = true;
            }
        }
    }
}

const std::vector<std::vector<int>>& LevelBuilder::GetLevel() const {
    return level;
}

bool LevelBuilder::ShouldLoadNextLevel() const {
    return loadNextLevel;
}
