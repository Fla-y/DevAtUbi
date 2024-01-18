#include "stdafx.h"
#include "AnimationManager.h"

/*AnimationSet[AnimationSet::WALK] = {
        PLAYER, 6, 1.0f / 15.0f, {0, 1, 2, 3, 4, 5}
    };
    AnimationSet[AnimationSet::WALK_BACK] = {
        PLAYER, 6, 1.0f / 15.0f, {6,7,8,9,10,11}
    };
    AnimationSet[AnimationSet::IDLE] = {
        PLAYER, 4, 1.0f / 25.0f, {50,51,52,53}
    };
    AnimationSet[AnimationSet::HURT] = {
        PLAYER, 2, 1.0f / 10.0f, {48,49}
    };
    AnimationSet[AnimationSet::DEATH] = {
        PLAYER, 6, 1.0f / 10.0f, {42,43,44,45,46,47}
    };
    AnimationSet[AnimationSet::JUMP] = {
        PLAYER, 6, 1.0f / 10.0f, {30,31,32,33,34,35}
    };
    AnimationSet[AnimationSet::ATTACK] = {
        PLAYER, 6, 1.0f / 10.0f, {24,25,26,27,28,29}
    };
    AnimationSet[AnimationSet::POWER_UP] = {
        PLAYER, 6, 1.0f / 10.0f, {12,13,14,15,16,17}
    };*/

AnimationManager::AnimationManager() {
}

AnimationManager::~AnimationManager() {
}

void AnimationManager::InitializePlayer() {
    
	player = App::CreateSprite(PLAYER.string().c_str(), 6, 9);
    player->CreateAnimation(static_cast<int>(AnimationSet::WALK), 1.0f / 12.0f, { 0, 1, 2, 3, 4, 5 });
    player->CreateAnimation(static_cast<int>(AnimationSet::WALK_BACK), 1.0f / 12.0f, { 6,7,8,9,10,11 });
    player->CreateAnimation(static_cast<int>(AnimationSet::IDLE), 1.0f / 5.0f, { 50,51,52,53 });
    player->CreateAnimation(static_cast<int>(AnimationSet::HURT), 1.0f / 15.0f, { 48,49 });
    player->CreateAnimation(static_cast<int>(AnimationSet::DEATH), 1.0f / 15.0f, { 42,43,44,45,46,47 });
    player->CreateAnimation(static_cast<int>(AnimationSet::JUMP), 1.0f / 15.0f, { 30,31,32,33,34,35 });
    player->CreateAnimation(static_cast<int>(AnimationSet::ATTACK), 1.0f / 15.0f, { 24,25,26,27,28,29 });
    player->CreateAnimation(static_cast<int>(AnimationSet::POWER_UP), 1.0f / 15.0f, { 12,13,14,15,16,17 });
    player->SetScale(2.5f);
    player->SetPosition(150.0f, 180.0f);

}

void AnimationManager::InitializeHammer()
{
    sprite = App::CreateSprite(HAMMER.string().c_str(), 8, 1);
    sprite->CreateAnimation(static_cast<int>(AnimationSet::HAMMER), 1.0f / 5.0f, { 0,1,2,3,4,5,6,7 });
    sprite->SetScale(6.0f);

}

CSimpleSprite* AnimationManager::GetSprite(SpriteType type) {

    switch (type)
    {
    case SpriteType::PLAYER:
        return player;
    case SpriteType::HAMMER:
        return sprite;
    default:
        return nullptr;
    }
}

