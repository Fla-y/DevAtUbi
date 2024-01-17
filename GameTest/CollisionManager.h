#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "stdafx.h"
#include "app/app.h"
#include "LogUtility.h"

struct BoundingBox {
    float left;
    float right;
    float top;
    float bottom;
};

class CollisionManager
{
public:
    CollisionManager(CSimpleSprite* sprite);
    void UpdateBoundingBox();

    bool CheckCollision(const CollisionManager& other) const;

    const BoundingBox& GetBoundingBox() const;

private:
    CSimpleSprite* mySprite;
    BoundingBox spriteBoundingBox;

    //BoundingBox GetBoundingBox(CSimpleSprite* sprite);
};

#endif 
