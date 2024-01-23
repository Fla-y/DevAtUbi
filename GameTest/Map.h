#ifndef BACKGROUND_BUILDER_H
#define BACKGROUND_BUILDER_H

#include "stdafx.h"
#include "app/app.h"
#include "LogUtility.h"

const float SCROLL_SPEED = 0.15f; // Pixels per second

class Map
{
public:
    Map(LogUtility& logger, bool& isInitSuccessful);
    ~Map();

    void DrawBackground();
    void DrawFloor();
    void Update(float deltaTime);


    //I need to find a better place for it
    //std::pair<float, float> ConvertPixelToVirtual(int px, int py);
    //--------------------------------------------------
private:
    using CSimpleSpritePtr = std::unique_ptr<CSimpleSprite>;

    float backgroundSpriteWidth;
    CSimpleSpritePtr backgroundSprite;
    std::vector<CSimpleSpritePtr> floorTiles;
    std::vector<CSimpleSpritePtr> backgroundSprites;
    int initTileCount,tileSize;
    LogUtility& logger;

    void UpdateBackground(float deltaTime);
    void InitializeBackground(bool& isInitSuccessful);
    void InitializeFloor(bool& isInitSuccessful);
    std::map<fs::path, std::string> mySpriteName;
};

#endif

