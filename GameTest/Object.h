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

	Object(LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful);
	~Object();
	void Animate(float deltaTime,float x, float y);
	void Draw();
	const CollisionManager& GetCollisionManager() const;
	void InitializeFrameDim();
	std::map<int, DimData> frameDimensions;

	bool IsActive() const;
	void Activate();
	void Deactivate();

	void SetPosition(float x, float y);
	void SetAngle(float a);
	void SetScale(float s);
	void GetPosition(float& x, float& y);
	float GetWidth();

private:

	LogUtility& logger;
	AnimationManager& animManager;
	CSimpleSpritePtr hammer;
	CollisionManager hammerCollision;
	bool isActive;

	void initializeHammer();
	
}; 

#endif 

