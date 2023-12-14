#ifndef PLAYER_H
#define PLAYER_H

#include "stdafx.h"
#include "app/app.h"
#include "Physics.h"

enum
{
    ANIM_FORWARDS,
    ANIM_BACKWARDS,
    ANIM_LEFT,
    ANIM_RIGHT,
};

class Player {

public:
    float x, y;       // Player position
    float velocityY;  // Vertical velocity
    bool isJumping;  
    float jumpVelocity;

    Player();
    ~Player();

    void Run(float deltaTime);
    void Jump(float deltaTime);
    CSimpleSprite* testSprite;

};

#endif

