#include "stdafx.h"
#include "AnimationManager.h"

/*playerAnimation[PlayerAnimation::WALK] = {
        PLAYER, 6, 1.0f / 15.0f, {0, 1, 2, 3, 4, 5}
    };
    playerAnimation[PlayerAnimation::WALK_BACK] = {
        PLAYER, 6, 1.0f / 15.0f, {6,7,8,9,10,11}
    };
    playerAnimation[PlayerAnimation::IDLE] = {
        PLAYER, 4, 1.0f / 25.0f, {50,51,52,53}
    };
    playerAnimation[PlayerAnimation::HURT] = {
        PLAYER, 2, 1.0f / 10.0f, {48,49}
    };
    playerAnimation[PlayerAnimation::DEATH] = {
        PLAYER, 6, 1.0f / 10.0f, {42,43,44,45,46,47}
    };
    playerAnimation[PlayerAnimation::MELEE] = {
        PLAYER, 6, 1.0f / 10.0f, {30,31,32,33,34,35}
    };
    playerAnimation[PlayerAnimation::ATTACK] = {
        PLAYER, 6, 1.0f / 10.0f, {24,25,26,27,28,29}
    };
    playerAnimation[PlayerAnimation::POWER_UP] = {
        PLAYER, 6, 1.0f / 10.0f, {12,13,14,15,16,17}
    };*/

AnimationManager::AnimationManager() {
	InitializePlayer();
}

AnimationManager::~AnimationManager() {
    delete player;
}

void AnimationManager::InitializePlayer() {
    

	player = App::CreateSprite(PLAYER.string().c_str(), 6, 9);

    player->CreateAnimation(static_cast<int>(PlayerAnimation::WALK), 1.0f / 15.0f, { 0, 1, 2, 3, 4, 5 });
    player->CreateAnimation(static_cast<int>(PlayerAnimation::WALK_BACK), 1.0f / 15.0f, { 6,7,8,9,10,11 });
    player->CreateAnimation(static_cast<int>(PlayerAnimation::IDLE), 1.0f / 5.0f, { 50,51,52,53 });
    player->CreateAnimation(static_cast<int>(PlayerAnimation::HURT), 1.0f / 15.0f, { 48,49 });
    player->CreateAnimation(static_cast<int>(PlayerAnimation::DEATH), 1.0f / 15.0f, { 42,43,44,45,46,47 });
    player->CreateAnimation(static_cast<int>(PlayerAnimation::MELEE), 1.0f / 15.0f, { 30,31,32,33,34,35 });
    player->CreateAnimation(static_cast<int>(PlayerAnimation::ATTACK), 1.0f / 15.0f, { 24,25,26,27,28,29 });
    player->CreateAnimation(static_cast<int>(PlayerAnimation::POWER_UP), 1.0f / 15.0f, { 12,13,14,15,16,17 });
    player->SetScale(1.0f);
    player->SetPosition(400.0f, 400.0f);

}

CSimpleSprite* AnimationManager::GetSprite() {
    if (player) {
        return player; 
    }
    return nullptr;
}

