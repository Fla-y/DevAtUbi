
#ifndef LEVELBUILDER_H
#define LEVELBUILDER_H

#include <vector>

class LevelBuilder {
public:
    // Constructor takes the vector from ReadFile
    LevelBuilder(const std::vector<char>& fileContents);

    // Function to build the level based on the file contents
    void BuildLevel(const std::vector<char>& fileContents, const std::vector<std::vector<int>>& levelData);

    // Function to get the built level
    const std::vector<std::vector<int>>& GetLevel() const;

    // Function to check if the next level needs to be loaded
    bool ShouldLoadNextLevel() const;

private:
    // Private member variable to store the built level
    std::vector<std::vector<int>> level;

    // Private member variable to track whether to load the next level
    bool loadNextLevel;
};

#endif 

