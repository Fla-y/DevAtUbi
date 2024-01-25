#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H


#include "stdafx.h"
#include "app/app.h"
#include "AnimationManager.h"
#include "LogUtility.h"
#include "CollisionManager.h"
#include "Object.h"

const float SCROLL_SPEED_COPY = 0.15f;

class ObjectPool
{
public:
	ObjectPool(unsigned int poolSize, LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful);
	~ObjectPool();

	std::vector<std::shared_ptr<Object>> GetActiveObjects();
	std::shared_ptr<Object> GetHammer();
	void ReleaseObject(std::shared_ptr<Object> object);
	void Update(float deltaTime);
	void Draw();

	/*bool IsActive() const;
	void Activate();
	void Deactivate();*/

private:
	std::vector<std::shared_ptr<Object>> activeObjects;
	std::vector<std::shared_ptr<Object>> pool;
	LogUtility& logger;
	AnimationManager& animManager;
};


#endif 