#ifndef LEVELBUILDER_H
#define LEVELBUILDER_H

#include "stdafx.h"

class LevelBuilder {
public:
    // Constructor takes the vector from FileReader
    LevelBuilder(const std::vector<char>& fileContents);

    void BuildLevel(const std::vector<char>& fileContents, const std::vector<std::vector<int>>& levelData);

    const std::vector<std::vector<int>>& GetLevel() const;

    bool ShouldLoadNextLevel() const;

private:

    std::vector<std::vector<int>> level;
    bool loadNextLevel;
};

#endif 

