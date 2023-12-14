#ifndef PLAYER_H
#define PLAYER_H

#include "stdafx.h"
#include "app/app.h"

enum
{
    ANIM_FORWARDS,
    ANIM_BACKWARDS,
    ANIM_LEFT,
    ANIM_RIGHT,
};

class Player {

public:
    Player();
    ~Player();

    CSimpleSprite* testSprite;
    void Run(float deltaTime);
    void Jump(float deltaTime);

};

#endif

