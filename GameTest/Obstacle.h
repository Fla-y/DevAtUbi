#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "stdafx.h"
#include "app/app.h"
#include "filePath.h"
#include "AnimationManager.h"
#include "LogUtility.h"
#include "CollisionManager.h"
#include "Object.h"

using CSimpleSpritePtr = std::unique_ptr<CSimpleSprite>;

class Obstacle
{
public:

	Obstacle(LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful, int& loopCounter, float& SCROLL_SPEED);
	~Obstacle();
	void Animate(float deltaTime);
	void Draw();
	const CollisionManager& GetCollisionManager() const;
	void InitializeFrameDim();
	std::map<int, DimData> frameDimensions;
	CSimpleSpritePtr hammer;
	int counter, copyCounter;
	const float HAMMERX = 1024.0f;
	const float HAMMERY = 98.0f;

private:

	float& scrollSpeed;
	LogUtility& logger;
	AnimationManager& animManager;
	CollisionManager hammerCollision;
	bool isActive;

	void RandomizeObstacle();
	
}; 

#endif 

