#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include "stdafx.h"
#include "app/app.h"
#include "filePath.h"

//const float cmath::PI = 3.14159265358979323846f;

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
	void Initializebox();

	std::map<fs::path, std::string> mySpriteName;

private:

	CSimpleSpritePtr player;
	CSimpleSpritePtr sprite;
	CSimpleSpritePtr box;
};

#endif

