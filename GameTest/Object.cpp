#include "stdafx.h"
#include "Object.h"
#include "App/app.h"

Object::Object(LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful, float& SCROLL_SPEED): 
	logger(logger),animManager(animManager),scrollSpeed(SCROLL_SPEED), isActive(false),isCollected(false),
	box(animManager.GetSprite(SpriteType::BOX)), boxCollision(CollisionManager(box))
{
    if (box == nullptr) {
        std::cerr << "Error: Failed to initialize box." << std::endl;
        logger.LogError("box initialization failed.");
        isInitSuccessful = false;
    }

    frameDimensions[0] = { 32.0f,32.0f };

    boxCollision.UpdateBoundingBox(frameDimensions, true);
}

void Object::FollowHammer(float deltaTime)
{
    if (isActive) {
        box->GetPosition(x, y);
        float newX = x - (scrollSpeed * deltaTime);
        box->SetPosition(newX, y);
        box->Update(deltaTime);
        boxCollision.UpdateBoundingBox(frameDimensions, true);
        //check if box is off screen
        if (newX + box->GetWidth() < 0) {
            box->SetPosition(1024.0f, 420.0f);
            isActive = false;
            isCollected = false;
        }
    }
}

void Object::Draw()
{
    box->Draw();
}

const CollisionManager& Object::GetCollisionManager() const
{
    return boxCollision;
}
