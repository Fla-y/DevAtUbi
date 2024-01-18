#include "stdafx.h"
#include "filePath.h"
#include "Map.h"
#include "App/main.h"


Map::Map(LogUtility& logger, bool& isInitSuccessful):initTileCount(32),tileSize(32),logger(logger) {
    InitializeBackground();
    InitializeFloor();
}

Map::~Map() {
}

void Map::DrawBackground() {
    if (backgroundSprite) {
        backgroundSprite->Draw();
    }

}

void Map::DrawFloor()
{
    for (auto& tile : floorTiles) {
        if (tile == nullptr) {
            std::cerr << "Error: Failed to initialize floor." << std::endl;
            logger.LogCriticalError("floor initialization failed.");
        }
        else {
            tile->Draw();
        }
    }
}

void Map::Update(float deltaTime) {
    const float tileWidth = 32.0f;    // Width of each tile

    // Move each tile
    for (auto it = floorTiles.begin(); it != floorTiles.end(); /* no increment */) {
        CSimpleSprite* tile = *it;
        float x, y;
        tile->GetPosition(x, y);
        float newX = x - (SCROLL_SPEED * deltaTime);
        tile->SetPosition(newX, y);

        // Check if tile is off-screen
        if (newX + tileWidth < 0) {
            delete tile; // Delete the off-screen tile
            it = floorTiles.erase(it); // Remove the tile from the vector
        }
        else {
            ++it;
        }
    }

    // Check if we need to add a new tile at the front
    if (!floorTiles.empty()) {
        CSimpleSprite* lastTile = floorTiles.back();
        float lastTileX, lastTileY;
        lastTile->GetPosition(lastTileX, lastTileY);

        // Add a new tile if there's space
        if (lastTileX + tileWidth < APP_VIRTUAL_WIDTH) {
            CSimpleSprite* newTile = App::CreateSprite(FLOOR_TILE.string().c_str(), 1, 1);
            newTile->SetPosition(lastTileX + tileWidth, lastTileY);
            floorTiles.push_back(newTile);
        }
    }
}

//
std::pair<float, float> Map::ConvertPixelToVirtual(int px, int py)
{
    float vx = (px / static_cast<float>(WINDOW_WIDTH)) * APP_VIRTUAL_WIDTH;
    float vy = (py / static_cast<float>(WINDOW_HEIGHT)) * APP_VIRTUAL_HEIGHT;
    return std::make_pair(vx, vy);
}

void Map::InitializeBackground()
{
    backgroundSprite = std::make_unique<CSimpleSprite>(BACKGROUND.string().c_str(), 1, 1);
    // In virtual coordinates, this places it at the middle of the screen
    backgroundSprite->SetPosition(APP_VIRTUAL_WIDTH * 0.5f, APP_VIRTUAL_HEIGHT * 0.5f);
    // Since the virtual resolution matches the sprite's size, we use a scale of 1.0f
    backgroundSprite->SetScale(1.0f);
    if (backgroundSprite == nullptr) {
        std::cerr << "Error: Failed to initialize background" << std::endl;
        logger.LogError("Background initialization failed.");
        bool isInitSuccesful = false;
    }
}

void Map::InitializeFloor() {
    for (int i = 0; i < initTileCount; ++i) {
        CSimpleSprite* tile = App::CreateSprite(FLOOR_TILE.string().c_str(), 1, 1);
        tile->SetScale(1.0f);
        tile->SetPosition(100.0f + i * tileSize, 100.0f);
        floorTiles.push_back(tile);
        if (tile == nullptr) {
            std::cerr << "Error: Failed to initialize floor tile" << std::endl;
            logger.LogError("floor tile initialization failed.");
            bool isInitSuccesful = false;
        }
    }
}
