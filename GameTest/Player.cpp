#include "stdafx.h"
#include "Player.h"
#include "app/app.h"

//GROUND 150.0F

Player::Player(LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful) : logger(logger), animManager(animManager),
isJumping(false), x(400.0f), y(400.0f), velocityY(0.0f),maxHeight(100.0f),
jumpVelocity(5.0f), sprite(animManager.GetSprite(SpriteType::PLAYER)),
collisionManager(sprite), isAlive(true),onGround(true)
{
    if (sprite == nullptr) {
        std::cerr << "Error: Failed to initialize player character." << std::endl;
        logger.LogCriticalError("Player character initialization failed.");
        isInitSuccessful = false;
    }
    sprite->SetAnimation(static_cast<int>(AnimationSet::WALK));
    
    CSimpleSprite* temp = App::CreateSprite(PLAYER_SIZE_SAMPLE.string().c_str(), 1, 1);
    frameDimensions[0] = { temp->GetHeight(),temp->GetWidth() };
    delete temp;

    collisionManager.UpdateBoundingBox(frameDimensions, true);

}

Player :: ~Player() {
}
//
//void Player::ReturnToIdle() {
//    sprite->SetAnimation(static_cast<int>(AnimationSet::IDLE));
//}

void Player::Move(float deltaTime) {
    
    sprite->Update(deltaTime);

    if (App::GetController().GetLeftThumbStickX() > 0.5f) {
        sprite->SetAnimation(static_cast<int>(AnimationSet::WALK_FASTER));
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
        sprite->SetAnimation(static_cast<int>(AnimationSet::WALK)); //ReturnToIdle();

    if (App::GetController().GetLeftThumbStickY() > 0.5f && !isJumping && onGround) {
        StartJump();
    }

    if (isJumping) {
        onGround = false;
        sprite->SetAnimation(static_cast<int>(AnimationSet::JUMP));
        sprite->GetPosition(x, y);
        collisionManager.UpdateBoundingBox(frameDimensions, true);
        y += velocityY * deltaTime;
        sprite->SetPosition(x, y);
        velocityY += -0.03f * deltaTime;
        // Check for collision with the ground
        if (y < 150.0f) {
            y = 150.0f;
            velocityY = 0;
            isJumping = false;
            onGround = true;
            sprite->SetPosition(x, y); // Reset position to ground level
        }
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
    isAlive = false;
    sprite->SetAnimation(static_cast<int>(AnimationSet::DEATH));
}

void Player::StartJump() {
    isJumping = true;
    velocityY = jumpVelocity;
}