#include "stdafx.h"
#include "CollisionManager.h"

CollisionManager::CollisionManager(CSimpleSprite* sprite) : mySprite(sprite)
{
}

void CollisionManager::UpdateBoundingBox(std::map<int,DimData>& frameDim, bool isPlayer )
{
    if (mySprite == nullptr) return;

    if (isPlayer) {  //Player sprite has the same dimensions for all the frames
        width = frameDim.at(0).width;
        height = frameDim.at(0).height;
    }
    else {
        width = frameDim.at(mySprite->GetFrame()).width;
        height = frameDim.at(mySprite->GetFrame()).height;
    }

    float x, y;
    mySprite->GetPosition(x, y);
    float scale = mySprite->GetScale();
    //considering x,y as the center of the sprite
    spriteBoundingBox.left = x - (width * scale) / 2.0f;
    spriteBoundingBox.right = x + (width * scale) / 2.0f;
    spriteBoundingBox.top = y + (height * scale)/2.0f;
    spriteBoundingBox.bottom = (y - (height * scale) / 2.0f) + 10.0f; //adjustment
}


// Method to check for collision with another sprite
bool CollisionManager::CheckCollision(const CollisionManager& other) const {
    const BoundingBox& otherBox = other.spriteBoundingBox;
    return !(spriteBoundingBox.left > otherBox.right || spriteBoundingBox.right < otherBox.left ||
        spriteBoundingBox.top < otherBox.bottom || spriteBoundingBox.bottom > otherBox.top);
}

// Accessor for the bounding box
const BoundingBox& CollisionManager::GetBoundingBox() const {
    return spriteBoundingBox;
}



//
//BoundingBox CollisionManager::GetBoundingBox(CSimpleSprite* sprite) {
//    float x, y;
//    sprite->GetPosition(x, y);
//
//    float width = sprite->GetWidth();
//    float height = sprite->GetHeight();
//    float scale = sprite->GetScale();
//
//    spriteBoundingBox.left = x - (width * scale) / 2.0f;
//    spriteBoundingBox.right = x + (width * scale) / 2.0f;
//    spriteBoundingBox.top = y - (height * scale) / 2.0f;
//    spriteBoundingBox.bottom = y + (height * scale) / 2.0f;
//}
