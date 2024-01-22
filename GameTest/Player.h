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
    float height, width,maxHeight;
    bool onGround;


    Player(LogUtility& logger, AnimationManager& animManager,bool& isInitSuccessful);
    ~Player();

    void Move(float deltaTime);
    void StartJump();
    void Draw();
    bool CheckCollision(const CollisionManager& other) const;
    //void Update(float deltaTime);
    void TriggerDeath();
    //void ReturnToIdle();

private:
    std::map<int, DimData> frameDimensions;
    LogUtility& logger;
    AnimationManager& animManager;
    CSimpleSprite* sprite;
    CollisionManager collisionManager;
   

};

#endif

