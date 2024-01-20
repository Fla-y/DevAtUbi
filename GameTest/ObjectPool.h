#include "stdafx.h"
#include "app/app.h"
#include "AnimationManager.h"
#include "LogUtility.h"
#include "CollisionManager.h"
#include "Object.h"


class ObjectPool
{
public:
	ObjectPool(unsigned int poolSize, LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful);
	~ObjectPool();
	Object* GetAvailableHammer();

private:
	std::vector<Object*> hammers;
	LogUtility& logger;
	AnimationManager& animManager;
};

