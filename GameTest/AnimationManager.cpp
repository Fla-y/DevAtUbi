#include "stdafx.h"
#include "AnimationManager.h"

AnimationManager::AnimationManager() {
}

AnimationManager::~AnimationManager() {
}


void AnimationManager::InitializePlayer() {
    std::string& spriteName = mySpriteName[PLAYER];
    if (spriteName.empty()) {
        spriteName = PLAYER.string();
    }

    player.reset(App::CreateSprite(spriteName.c_str(), 6, 9));
    player->CreateAnimation(static_cast<int>(AnimationSet::WALK), 1.0f / 11.0f, { 0, 1, 2, 3, 4, 5 });
    player->CreateAnimation(static_cast<int>(AnimationSet::WALK_BACK), 1.0f / 11.0f, { 6,7,8,9,10,11 });
    player->CreateAnimation(static_cast<int>(AnimationSet::IDLE), 1.0f / 8.0f, { 50,51,52,53 });
    player->CreateAnimation(static_cast<int>(AnimationSet::HURT), 1.0f / 15.0f, { 48,49 });
    player->CreateAnimation(static_cast<int>(AnimationSet::DEATH), 1.0f / 15.0f, { 42,43,44,45,46,47 });
    player->CreateAnimation(static_cast<int>(AnimationSet::JUMP), 1.0f / 15.0f, { 30,31,32,33,34,35 });
    player->CreateAnimation(static_cast<int>(AnimationSet::ATTACK), 1.0f / 15.0f, { 24,25,26,27,28,29 });
    player->CreateAnimation(static_cast<int>(AnimationSet::POWER_UP), 1.0f / 15.0f, { 12,13,14,15,16,17 });
    player->CreateAnimation(static_cast<int>(AnimationSet::WALK_FASTER), 1.0f / 18.0f, { 0, 1, 2, 3, 4, 5 });
    player->SetScale(2.5f);
    player->SetPosition(150.0f, 150.0f);

}

void AnimationManager::InitializeHammer()
{
    std::string& spriteName = mySpriteName[HAMMER];
    if (spriteName.empty()) {
        spriteName = HAMMER.string();
    }
    sprite.reset( App::CreateSprite(spriteName.c_str(), 8, 1));
    sprite->CreateAnimation(static_cast<int>(AnimationSet::HAMMER), 1.0f / 5.0f, { 0,1,2,3,4,5,6,7 });
    sprite->SetScale(3.0f);
    sprite->SetAngle(3.14159f);
    sprite->SetPosition(1024.0f, 98.0f);

}

CSimpleSpritePtr AnimationManager::GetSprite(SpriteType type) {

    switch (type)
    {
    case SpriteType::PLAYER:
        return std::move(player);
    case SpriteType::HAMMER:
        return std::move(sprite);
    default:
        return nullptr;
    }
}

