#ifndef OBJECT_H
#define OBJECT_H

#include "stdafx.h"
#include "app/app.h"
#include "filePath.h"
#include "AnimationManager.h"
#include "LogUtility.h"
#include "CollisionManager.h"

using CSimpleSpritePtr = std::unique_ptr<CSimpleSprite>;

class Object
{
public:
	Object(LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful, float& SCROLL_SPEED);
	bool isActive,isCollected;
	void FollowHammer(float deltaTime);
	void Draw();
	const CollisionManager& GetCollisionManager() const;

private:
	float x, y;
	float& scrollSpeed;
	LogUtility& logger;
	AnimationManager& animManager;
	CSimpleSpritePtr box;
	CollisionManager boxCollision;
	std::map<int, DimData> frameDimensions;

};

#endif 