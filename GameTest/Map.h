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
    std::pair<float, float> ConvertPixelToVirtual(int px, int py);
    //--------------------------------------------------
private:
    CSimpleSprite* backgroundSprite;
    void InitializeBackground();
    void InitializeFloor();
    std::vector<CSimpleSprite*> floorTiles;
    int initTileCount,tileSize;
    LogUtility& logger;
};

#endif

