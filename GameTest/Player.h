#ifndef PLAYER_H
#define PLAYER_H

#include "stdafx.h"
#include "app/app.h"
#include "AnimationManager.h"
#include "LogUtility.h"
#include "CollisionManager.h"

class Player {

public:
    float x, y;       // Player position
    float velocityY;  // Vertical velocity
    bool isJumping;  
    float jumpVelocity;
    bool isAlive;
    bool onGround,isInvincible;

    std::chrono::steady_clock::time_point startTime;
    const std::chrono::seconds duration{ 5 };

    Player(LogUtility& logger, AnimationManager& animManager,bool& isInitSuccessful);
    ~Player();

    void ReturnToIdle(float deltaTime);
    void Move(float deltaTime);
    void StartJump();
    void Draw();
    bool CheckCollision(const CollisionManager& other) const;
    void TriggerDeath();
    void TriggerPowerUp();

private:
    using CSimpleSpritePtr = std::unique_ptr<CSimpleSprite>;

    std::map<int, DimData> frameDimensions;
    LogUtility& logger;
    AnimationManager& animManager;
    CSimpleSpritePtr sprite;
    CollisionManager collisionManager;

    std::map<fs::path, std::string> mySpriteName;

   

};

#endif

