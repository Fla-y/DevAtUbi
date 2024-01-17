#include "stdafx.h"
#include "Object.h"

Object::Object(LogUtility& logger, AnimationManager& animManager): logger(logger), animManager(animManager)
{
    hammer = animManager.GetSprite(SpriteType::HAMMER);
    if (hammer == nullptr) {
        std::cerr << "Error: Failed to initialize hammer." << std::endl;
        logger.LogError("Hammer initialization failed.");
    }
}

void Object::Animate()
{
    hammer->SetAnimation(static_cast<int>(AnimationSet::HAMMER));
    hammer->SetPosition(400.0f, 400.0f);
    hammer->Draw();
}
