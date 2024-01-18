#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include "stdafx.h"
#include "app/app.h"
#include "filePath.h"

enum class AnimationSet
{
	WALK,
	WALK_BACK,
	IDLE,
	HURT,
	DEATH,
	JUMP,
	ATTACK,
	POWER_UP,
	HAMMER,
};

enum class SpriteType
{
	PLAYER,
	HAMMER,
};

class AnimationManager
{
public:

	AnimationManager();
	~AnimationManager();

	CSimpleSprite* GetSprite(SpriteType type);
	void InitializePlayer();
	void InitializeHammer();

private:

	CSimpleSprite* player;
	CSimpleSprite* sprite;
};

#endif

