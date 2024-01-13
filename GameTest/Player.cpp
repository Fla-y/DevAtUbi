#include "stdafx.h"
#include "Player.h"
#include "app/app.h"

Player::Player() : isJumping(false), x(400.0f), y(400.0f), velocityY(0.0f), jumpVelocity(0.2f) {
    sprite=animManager.GetSprite();
    sprite->SetAnimation(static_cast<int>(PlayerAnimation::IDLE));
}

Player :: ~Player() {
}

void Player::ReturnToIdle() {
    sprite->SetAnimation(static_cast<int>(PlayerAnimation::IDLE));
}

void Player::Run(float deltaTime) {
    
    sprite->Update(deltaTime);

    if (App::GetController().GetLeftThumbStickX() > 0.5f) {
        sprite->SetAnimation(static_cast<int>(PlayerAnimation::WALK));
        sprite->GetPosition(x, y);
        x += 1.0f;
        sprite->SetPosition(x, y);
        if (!(App::GetController().GetLeftThumbStickX() > 0.5f)) {
            ReturnToIdle();
        }
    }

    if (App::GetController().GetLeftThumbStickX() < -0.5f) {
        sprite->SetAnimation(static_cast<int>(PlayerAnimation::WALK_BACK));
        sprite->GetPosition(x, y);
        x -= 1.0f;
        sprite->SetPosition(x, y);
    }

    if (App::GetController().GetLeftThumbStickY() > 0.5f) {
        sprite->SetAnimation(static_cast<int>(PlayerAnimation::IDLE));
        sprite->GetPosition(x, y);
        y += 1.0f;
        sprite->SetPosition(x, y);
    }

    if (App::GetController().GetLeftThumbStickY() < -0.5f) {
        sprite->SetAnimation(static_cast<int>(PlayerAnimation::ATTACK));
        sprite->GetPosition(x, y);
        y -= 1.0f;
        sprite->SetPosition(x, y);
    }

    if (App::GetController().GetLeftThumbStickY() && !isJumping) {
        sprite->SetAnimation(static_cast<int>(PlayerAnimation::MELEE));
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

