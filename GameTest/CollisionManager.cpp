#include "stdafx.h"
#include "CollisionManager.h"

CollisionManager::CollisionManager(CSimpleSprite* sprite) : mySprite(sprite)
{
    if (sprite != nullptr) {
        UpdateBoundingBox();
    }
}

void CollisionManager::UpdateBoundingBox()
{
    if (mySprite == nullptr) return;

    float x, y;
    mySprite->GetPosition(x, y);
                   
    float width = mySprite->GetWidth();
    float height = mySprite->GetHeight();
    float scale = mySprite->GetScale();

    // Assuming the position (x, y) is the center of the sprite
    spriteBoundingBox.left = x - (width * scale) / 2.0f;
    spriteBoundingBox.right = x + (width * scale) / 2.0f;
    spriteBoundingBox.top = y + (height * scale) / 2.0f;
    spriteBoundingBox.bottom = y - (height * scale) / 2.0f;
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
