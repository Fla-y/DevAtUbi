#include "stdafx.h"
#include "ObjectPool.h"


ObjectPool::ObjectPool(unsigned int poolSize, LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful) : 
	logger(logger), animManager(animManager)
{
	for (unsigned int i = 0; i < poolSize; ++i) {
		pool.push_back(std::make_shared<Object>(logger, animManager, isInitSuccessful));
	}
}

ObjectPool::~ObjectPool()
{
}

std::vector<std::shared_ptr<Object>> ObjectPool::GetActiveObjects()
{
    return activeObjects;
}

std::shared_ptr<Object> ObjectPool::GetHammer() {
    if (!pool.empty()) {
        auto object = pool.back();
        pool.pop_back();
        activeObjects.push_back(object);
        // Initialize and activate the object
        return object;
    }
    return nullptr; // Pool is empty
}

void ObjectPool::ReleaseObject(std::shared_ptr<Object> object) {
    activeObjects.erase(std::remove(activeObjects.begin(), activeObjects.end(), object), activeObjects.end());
    pool.push_back(object);
}

void ObjectPool::Update(float deltaTime) {
    for (auto& object : activeObjects) {
        float x, y;

        object->GetPosition(x, y);
        x -= SCROLL_SPEED_COPY * deltaTime;

        object->Animate(deltaTime, x, y); 

        // Check if the object is off-screen and release it
        if (x + object->GetWidth() < 0) { 
            ReleaseObject(object);
        }
    }
}

void ObjectPool::Draw() {
    for (auto& object : activeObjects) {
        object->Draw();
    }
}