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
	WALK_FASTER,
	HAMMER,
};

enum class SpriteType
{
	PLAYER,
	HAMMER,
	BOX,
};

using CSimpleSpritePtr = std::unique_ptr<CSimpleSprite>;

class AnimationManager
{
public:

	AnimationManager();
	~AnimationManager();

	CSimpleSpritePtr GetSprite(SpriteType type);
	void InitializePlayer();
	void InitializeHammer();
	void InitializeBox();


private:
	std::map<fs::path, std::string> mySpriteName;
	CSimpleSpritePtr player;
	CSimpleSpritePtr sprite;
	CSimpleSpritePtr box;
};

#endif

