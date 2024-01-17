#ifndef OBJECT_H
#define OBJECT_H

#include "stdafx.h"
#include "app/app.h"
#include "filePath.h"
#include "AnimationManager.h"
#include "LogUtility.h"

class Object
{
public:

	Object(LogUtility& logger, AnimationManager& animManager);
	//~Object();
	void Animate();

	

private:
	LogUtility& logger;
	AnimationManager& animManager;
	CSimpleSprite* hammer;
}; 

#endif 

