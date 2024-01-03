#include "stdafx.h"
#include "Player.h"
#include "app/app.h"

Player::Player() : isJumping(false), x(400.0f), y(400.0f), velocityY(0.0f), jumpVelocity(0.2f) {
    testSprite = App::CreateSprite(".\\TestData\\Test.bmp", 8, 4);
    testSprite->SetPosition(x, y);
    float speed = 1.0f / 15.0f;
    testSprite->CreateAnimation(ANIM_BACKWARDS, speed, { 0,1,2,3,4,5,6,7 });
    testSprite->CreateAnimation(ANIM_LEFT, speed, { 8,9,10,11,12,13,14,15 });
    testSprite->CreateAnimation(ANIM_RIGHT, speed, { 16,17,18,19,20,21,22,23 });
    testSprite->CreateAnimation(ANIM_FORWARDS, speed, { 24,25,26,27,28,29,30,31 });
    testSprite->SetScale(1.0f);
}

Player :: ~Player() {
    delete testSprite;
}

void Player::Run(float deltaTime) {
    
    testSprite->Update(deltaTime);

    if (App::GetController().GetLeftThumbStickX() > 0.5f) {
        testSprite->SetAnimation(ANIM_RIGHT);
        testSprite->GetPosition(x, y);
        x += 1.0f;
        testSprite->SetPosition(x, y);
    }

    if (App::GetController().GetLeftThumbStickX() < -0.5f) {
        testSprite->SetAnimation(ANIM_LEFT);
        testSprite->GetPosition(x, y);
        x -= 1.0f;
        testSprite->SetPosition(x, y);
    }

    if (App::GetController().GetLeftThumbStickY() > 0.5f) {
        testSprite->SetAnimation(ANIM_FORWARDS);
        testSprite->GetPosition(x, y);
        y += 1.0f;
        testSprite->SetPosition(x, y);
    }

    if (App::GetController().GetLeftThumbStickY() < -0.5f) {
        testSprite->SetAnimation(ANIM_BACKWARDS);
        testSprite->GetPosition(x, y);
        y -= 1.0f;
        testSprite->SetPosition(x, y);
    }

    if (App::GetController().GetLeftThumbStickY() && !isJumping) {
        testSprite->SetAnimation(ANIM_BACKWARDS);
        testSprite->GetPosition(x, y);
        Jump(deltaTime);
        testSprite->SetPosition(x, y);
   
    }

}

void Player::Jump(float deltaTime) {
    velocityY += jumpVelocity;
    isJumping = true;
    y += velocityY * deltaTime;
    isJumping = false;
}

