#include "stdafx.h"
#include "ObjectPool.h"

ObjectPool::ObjectPool(unsigned int poolSize, LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful) : 
	logger(logger), animManager(animManager)
{
	for (unsigned int i = 0; i < poolSize; ++i) {
		hammers.push_back(new Object(logger, animManager, isInitSuccessful));
	}
}

ObjectPool::~ObjectPool()
{
	for (auto* hammer : hammers) {
		delete hammer;
	}
}

Object* ObjectPool::GetAvailableHammer()
{
	for (auto* hammer : hammers) {
		/*if (!hammer->IsActive()) {
			hammer->Activate();
			return hammer;
		}*/
	}
	return nullptr; 
}

//
//bool ObjectPool::IsActive() const {
//	return isActive;
//}
//
//void ObjectPool::Activate() {
//	isActive = true;
//	 Additional code to initialize the object for use
//}
//
//void ObjectPool::Deactivate() {
//	isActive = false;
//	 Additional code to reset the object for future use
//}
