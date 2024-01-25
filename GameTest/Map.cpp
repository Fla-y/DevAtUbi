#include "stdafx.h"
#include "filePath.h"
#include "Map.h"
#include "App/main.h"


Map::Map(LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful):
    initTileCount(32),tileSize(32),logger(logger), animManager(animManager), 
    hammerPool(15,logger,animManager,isInitSuccessful)
{
    InitializeBackground(isInitSuccessful);
    InitializeFloor(isInitSuccessful);
}

Map::~Map() {
}

void Map::DrawBackground() {
    for (auto& bgSprite : backgroundSprites) {
        if (bgSprite) {
            bgSprite->Draw();
        }
    }
}

void Map::DrawFloor()
{
    for (auto& tile : floorTiles) {
        if (tile == nullptr) {
            std::cerr << "Error: Failed to initialize floor." << std::endl;
            logger.LogError("floor initialization failed.");
        }
        else {
            tile->Draw();
        }
    }
}

void Map::DrawObject() {
    auto activeHammers=hammerPool.GetActiveObjects();
    for (auto& hammer : activeHammers) {
        if (hammer != nullptr) {
            hammer->Draw(); // Draw each active hammer
        }
    }
}

void Map::Update(float deltaTime) {
    const float tileWidth = 32.0f;

    // Move each tile
    for (auto it = floorTiles.begin(); it != floorTiles.end();) {
        CSimpleSprite& tile = *(*it);
        float x, y;
        tile.GetPosition(x, y);
        float newX = x - (SCROLL_SPEED * deltaTime);
        tile.SetPosition(newX, y);

        // Check if tile is off-screen
        if (newX + tileWidth < 0) {
            it = floorTiles.erase(it); // Remove the tile from the vector
        }
        else {
            ++it;
        }
    }

    // Check if we need to add a new tile at the front
    if (!floorTiles.empty()) {
        CSimpleSprite& lastTile = *floorTiles.back();
        float lastTileX, lastTileY;
        lastTile.GetPosition(lastTileX, lastTileY);

        // Add a new tile if there's space
        if (lastTileX + tileWidth < APP_VIRTUAL_WIDTH) {
            CSimpleSpritePtr newTile{ App::CreateSprite(FLOOR_TILE.string().c_str(), 1, 1) };
            newTile->SetPosition(lastTileX + tileWidth, lastTileY);
            floorTiles.push_back(std::move(newTile));
        }
    }

    UpdateBackground(deltaTime);
    UpdateObstacles(deltaTime);
}

void Map::InitializeBackground(bool& isInitSuccessful)
{
    const int numBackgroundSprites = 10; // Including buffer sprite
    for (int i = 0; i < numBackgroundSprites; ++i) {

        std::string& spriteName = mySpriteName[BACKGROUND];
        if (spriteName.empty()) {
            spriteName = BACKGROUND.string();
        }

        CSimpleSpritePtr bgSprite{ App::CreateSprite(spriteName.c_str(), 1, 1)};
        bgSprite->SetScale(1.0f);

        float spriteWidth = bgSprite->GetWidth();
        bgSprite->SetPosition(i * spriteWidth, APP_VIRTUAL_HEIGHT * 0.5f);
        if (bgSprite == nullptr) {
            std::cerr << "Error: Failed to initialize background" << std::endl;
            logger.LogError("Background initialization failed.");
        }
        backgroundSprites.push_back(std::move(bgSprite));
    }
    backgroundSpriteWidth = backgroundSprites.front()->GetWidth();
}

void Map::InitializeFloor(bool& isInitSuccessful) {
    for (int i = 0; i < initTileCount; ++i) {
        std::string& spriteName = mySpriteName[FLOOR_TILE];
        if (spriteName.empty()) {
            spriteName = FLOOR_TILE.string();
        }

        CSimpleSpritePtr tile{ App::CreateSprite(spriteName.c_str(), 1, 1) };
        tile->SetScale(1.0f);
        tile->SetPosition(0.0f + i * tileSize, 15.0f);
        if (tile == nullptr) {
            std::cerr << "Error: Failed to initialize floor tile" << std::endl;
            logger.LogError("floor tile initialization failed.");
        }
        floorTiles.push_back(std::move(tile));
    }
}
   
void Map::UpdateBackground(float deltaTime)
{
    for (auto& bgSprite : backgroundSprites) {
        float x, y;
        bgSprite->GetPosition(x, y);
        float newX = x - (SCROLL_SPEED * deltaTime);
        bgSprite->SetPosition(newX, y);

        // Reset and reuse the sprite that goes off-screen
        if (newX + backgroundSpriteWidth < 0) {
            float lastSpriteX, lastSpriteY;
            backgroundSprites.back()->GetPosition(lastSpriteX, lastSpriteY);
            bgSprite->SetPosition(lastSpriteX + backgroundSpriteWidth, lastSpriteY);
        }
    }
}

void Map::UpdateObstacles(float deltaTime) {
    spawnTimer -= deltaTime;
    if (spawnTimer <= 0) {
        auto newObject = hammerPool.GetHammer(); // Retrieve an object from the pool
        if (newObject != nullptr) {
            // Set initial position (right of the screen)
            newObject->SetPosition(APP_VIRTUAL_WIDTH, 100.0f);
        }
        spawnTimer = 100.0f; // Reset timer
    }

    hammerPool.Update(deltaTime); // Update all active objects
}

ObjectPool& Map::GetHammerPool() {
    return hammerPool;
}