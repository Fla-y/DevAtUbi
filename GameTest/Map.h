#ifndef BACKGROUND_BUILDER_H
#define BACKGROUND_BUILDER_H

#include "stdafx.h"
#include "app/app.h"
#include "LogUtility.h"
#include "ObjectPool.h"
#include "Object.h"

const float SCROLL_SPEED = 0.15f; // Pixels per second

using CSimpleSpritePtr = std::unique_ptr<CSimpleSprite>;
using ObjSharedPtr = std::shared_ptr<Object>;

class Map
{
public:
    Map(LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful);
    ~Map();

    void DrawBackground();
    void DrawFloor();
    void DrawObject();
    void Update(float deltaTime);
    ObjectPool& GetHammerPool();


private:
    float backgroundSpriteWidth;
    CSimpleSpritePtr backgroundSprite;
    std::vector<CSimpleSpritePtr> floorTiles;
    std::vector<CSimpleSpritePtr> backgroundSprites;
    ObjectPool hammerPool;
    int initTileCount,tileSize;
    LogUtility& logger;
    AnimationManager& animManager;

    void UpdateBackground(float deltaTime);
    void UpdateObstacles(float deltaTime);
    void InitializeBackground(bool& isInitSuccessful);
    void InitializeFloor(bool& isInitSuccessful);
    std::map<fs::path, std::string> mySpriteName;

    float spawnTimer = 0.0f;
    const float spawnInterval = 2.0f;
    const int maxObjects = 15;

};

#endif

