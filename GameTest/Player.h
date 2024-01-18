#ifndef PLAYER_H
#define PLAYER_H

#include "stdafx.h"
#include "app/app.h"
#include "Physics.h"
#include "AnimationManager.h"
#include "LogUtility.h"
#include "CollisionManager.h"

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
    bool isAlive;
    float height, width;

    const float GRAVITY = 9.0f;
    const float MAX_VELOCITY = -10.0f;
    const float MAX_AIR_TIME = 1.2f;

    bool onGround;
    float timeInAir = 0.0f;
    float jumpImpulseTime = 0.2f;
    float jumpImpulseVel = -10.0f;
    float jumpAccel = -1.0f;


    Player(LogUtility& logger, AnimationManager& animManager,bool& isInitSuccessful);
    ~Player();

    void Move(float deltaTime);
    void Jump(float deltaTime);
    void Draw();
    bool CheckCollision(const CollisionManager& other) const;
    void Update(float deltaTime);
    void TriggerDeath();
    std::map<int, DimData> frameDimensions;

private:
    LogUtility& logger;
    AnimationManager& animManager;
    CSimpleSprite* sprite;
    CollisionManager collisionManager;
    void ReturnToIdle();

};

#endif

