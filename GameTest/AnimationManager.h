#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include "stdafx.h"
#include "app/app.h"
#include "filePath.h"

enum class PlayerAnimation
{
	WALK,
	WALK_BACK,
	IDLE,
	HURT,
	DEATH,
	MELEE,
	ATTACK,
	POWER_UP,
};


class AnimationManager
{
public:

	AnimationManager();
	~AnimationManager();

	CSimpleSprite* GetSprite();

private:

	struct AnimationData {
		std::filesystem::path filePath;
		int columns = 0;
		float speed = 0;
		std::vector<int> frameSequence;
	};
	void InitializePlayer();
	CSimpleSprite* player;
	//std::map<PlayerAnimation, AnimationData> playerAnimation;
	
};

#endif

