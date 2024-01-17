#include "stdafx.h"
#include "Player.h"
#include "app/app.h"

Player::Player(LogUtility& logger, AnimationManager& animManager) : logger(logger), animManager(animManager), isJumping(false), x(400.0f), y(400.0f), velocityY(0.0f), jumpVelocity(0.2f) {
    sprite=animManager.GetSprite(SpriteType::PLAYER);
    if (sprite == nullptr) {
        std::cerr << "Error: Failed to initialize player character." << std::endl;
        logger.LogCriticalError("Player character initialization failed.");
    }
    sprite->SetAnimation(static_cast<int>(AnimationSet::IDLE));
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

    if (App::GetController().GetLeftThumbStickY() > 0.5f) {
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
    }

    if (App::GetController().GetLeftThumbStickY() && !isJumping) {
        sprite->SetAnimation(static_cast<int>(AnimationSet::MELEE));
        sprite->GetPosition(x, y);
        Jump(deltaTime);
        sprite->SetPosition(x, y);
   
    }

}

void Player::Jump(float deltaTime) {
    velocityY += jumpVelocity;
    isJumping = true;
    y += velocityY * deltaTime;
    isJumping = false;
}

