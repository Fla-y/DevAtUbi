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
    ANIM_JUMP,
};

class Player {

public:
    Player();
    ~Player();

    CSimpleSprite* testSprite;
    void Walk(float deltaTime);
    void Jump(float deltaTime);

private:
    bool isJumping;  // Flag to track if the player is currently jumping
    float jumpDuration;  // Total duration of the jump animation
    float jumpTimer;  // Timer to track the current position in the jump animation

    void Move(float offsetX, float offsetY);  // Helper method for movement
};

#endif

