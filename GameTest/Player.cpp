#include "stdafx.h"
#include "Player.h"
#include "app/app.h"

Player:: Player() : isJumping(false), jumpDuration(500.0f), jumpTimer(0.0f) {
    testSprite = App::CreateSprite(".\\TestData\\Test.bmp", 8, 4);
    testSprite->SetPosition(400.0f, 400.0f);
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

void Player::Walk (float deltaTime) {
    testSprite->Update(deltaTime);

    if (App::GetController().GetLeftThumbStickX() > 0.5f) {
        testSprite->SetAnimation(ANIM_RIGHT);
        float x, y;
        testSprite->GetPosition(x, y);
        x += 1.0f;
        testSprite->SetPosition(x, y);
    }

    if (App::GetController().GetLeftThumbStickX() < -0.5f) {
        testSprite->SetAnimation(ANIM_LEFT);
        float x, y;
        testSprite->GetPosition(x, y);
        x -= 1.0f;
        testSprite->SetPosition(x, y);
    }

    //-------------------------------------------------------
    //per ora non mi serve che vadano su e giù, ma dopo non so
    /* 
    if (App::GetController().GetLeftThumbStickY() > 0.5f) {
        testSprite->SetAnimation(ANIM_FORWARDS);
        float x, y;
        testSprite->GetPosition(x, y);
        y += 1.0f;
        testSprite->SetPosition(x, y);
    }
    */
    /*
    if (App::GetController().GetLeftThumbStickY() < -0.5f) {
        testSprite->SetAnimation(ANIM_BACKWARDS);
        float x, y;
        testSprite->GetPosition(x, y);
        y -= 1.0f;
        testSprite->SetPosition(x, y);
    }
    */
}

