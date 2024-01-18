#include "stdafx.h"
#include "Player.h"
#include "app/app.h"

Player::Player(LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful) : logger(logger), animManager(animManager),
isJumping(false), x(400.0f), y(400.0f), velocityY(0.0f),maxHeight(100.0f),
jumpVelocity(0.8f), sprite(animManager.GetSprite(SpriteType::PLAYER)),
collisionManager(sprite), isAlive(true),onGround(true)
{
    if (sprite == nullptr) {
        std::cerr << "Error: Failed to initialize player character." << std::endl;
        logger.LogCriticalError("Player character initialization failed.");
        isInitSuccessful = false;
    }
    sprite->SetAnimation(static_cast<int>(AnimationSet::IDLE));
    
    CSimpleSprite* temp = App::CreateSprite(PLAYER_SIZE_SAMPLE.string().c_str(), 1, 1);
    frameDimensions[0] = { temp->GetHeight(),temp->GetWidth() };
    delete temp;

    collisionManager.UpdateBoundingBox(frameDimensions, true);

}

Player :: ~Player() {
}

void Player::ReturnToIdle() {
    sprite->SetAnimation(static_cast<int>(AnimationSet::IDLE));
}

void Player::Move(float deltaTime) {
    
    sprite->Update(deltaTime);

    if (App::GetController().GetLeftThumbStickX() > 0.5f) {
        sprite->SetAnimation(static_cast<int>(AnimationSet::WALK));
        sprite->GetPosition(x, y);
        x += 1.0f;
        sprite->SetPosition(x, y);
    }
    else if (App::GetController().GetLeftThumbStickX() < -0.5f) {
        sprite->SetAnimation(static_cast<int>(AnimationSet::WALK_BACK));
        sprite->GetPosition(x, y);
        x -= 1.0f;
        sprite->SetPosition(x, y);
    }
    else
        ReturnToIdle();

   /* if (App::GetController().GetLeftThumbStickY() > 0.5f) {
        sprite->SetAnimation(static_cast<int>(AnimationSet::IDLE));
        sprite->GetPosition(x, y);
        y += 1.0f;
        sprite->SetPosition(x, y);
    }

    if (App::GetController().GetLeftThumbStickY() < -0.5f) {
        sprite->SetAnimation(static_cast<int>(AnimationSet::ATTACK));
        sprite->GetPosition(x, y);
        y -= 1.0f;
        sprite->SetPosition(x, y);
    }*/

    if (App::GetController().GetLeftThumbStickY() > 0.5f && onGround) {
        sprite->SetAnimation(static_cast<int>(AnimationSet::JUMP));
        sprite->GetPosition(x, y);
        Jump(deltaTime);
        sprite->SetPosition(x, y);
   
    }

    collisionManager.UpdateBoundingBox(frameDimensions,true);

}

void Player::Draw() {
    sprite->Draw();
}

bool Player::CheckCollision(const CollisionManager& other) const {
    return collisionManager.CheckCollision(other);
}

void Player::TriggerDeath()
{
    sprite->SetAnimation(static_cast<int>(AnimationSet::DEATH));
    isAlive = false;
}

void Player::Jump(float deltaTime) {
    velocityY += jumpVelocity;
    onGround = false;
    y += velocityY * deltaTime; 
    velocityY = -1;
    y -= velocityY * deltaTime;
    onGround = true;
    
}