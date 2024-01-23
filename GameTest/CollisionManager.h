#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "stdafx.h"
#include "app/app.h"
#include "LogUtility.h"


struct DimData {
    float height;
    float width;
};

struct BoundingBox {
    float left;
    float right;
    float top;
    float bottom;
};

using CSimpleSpritePtr = std::unique_ptr<CSimpleSprite>;

class CollisionManager
{
public:
    CollisionManager(CSimpleSpritePtr& sprite);
    void UpdateBoundingBox(std::map<int,DimData>& frameDim, bool isPlayer);

    bool CheckCollision(const CollisionManager& other) const;

    const BoundingBox& GetBoundingBox() const;

private:
    CSimpleSpritePtr& mySprite;
    BoundingBox spriteBoundingBox;
    float height, width;
};

#endif 
