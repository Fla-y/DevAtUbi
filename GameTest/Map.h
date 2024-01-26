#ifndef BACKGROUND_BUILDER_H
#define BACKGROUND_BUILDER_H

#include "stdafx.h"
#include "app/app.h"
#include "LogUtility.h"
#include "filePath.h"

//base SCROLL_SPEED = 0.25f; 

class Map
{
public:
    Map(LogUtility& logger, bool& isInitSuccessful, int& loopCounter, float& SCROLL_SPEED);
    ~Map();

    void DrawBackground();
    void DrawFloor();
    void Update(float deltaTime);
    
private:
    using CSimpleSpritePtr = std::unique_ptr<CSimpleSprite>;
    float& scrollSpeed;
    float backgroundSpriteWidth;
    CSimpleSpritePtr backgroundSprite;
    std::vector<CSimpleSpritePtr> floorTiles;
    std::vector<CSimpleSpritePtr> backgroundSprites;
    int initTileCount,tileSize,loopCounter;
    LogUtility& logger;

    void UpdateBackground(float deltaTime);
    void InitializeBackground(bool& isInitSuccessful);
    void InitializeFloor(bool& isInitSuccessful);
    std::map<fs::path, std::string> mySpriteName;
};

#endif

