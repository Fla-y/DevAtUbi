#ifndef OBJECT_H
#define OBJECT_H

#include "stdafx.h"
#include "app/app.h"
#include "filePath.h"
#include "AnimationManager.h"
#include "LogUtility.h"
#include "CollisionManager.h"


class Object
{
public:

	Object(LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful);
	~Object();
	void Animate(float deltaTime);
	void Draw();
	const CollisionManager& GetCollisionManager() const;
	void InitializeFrameDim();
	std::map<int, DimData> frameDimensions;

	bool IsActive() const;
	void Activate();
	void Deactivate();

private:

	using CSimpleSpritePtr = std::unique_ptr<CSimpleSprite>;

	LogUtility& logger;
	AnimationManager& animManager;
	CSimpleSpritePtr hammer;
	CollisionManager hammerCollision;
	bool isActive;
	
}; 

#endif 

