#include "stdafx.h"
#include "App/app.h"
#include "Object.h"

Object::Object(LogUtility& logger, AnimationManager& animManager,bool& isInitSuccessful): logger(logger), animManager(animManager), 
hammer(animManager.GetSprite(SpriteType::HAMMER)), hammerCollision( CollisionManager(hammer))
{
    if (hammer == nullptr) {
        std::cerr << "Error: Failed to initialize hammer." << std::endl;
        logger.LogError("Hammer initialization failed.");
        bool isInitSuccesful = false;
    }
    InitializeFrameDim();
}

Object::~Object()
{
   
}

void Object::Animate(float deltaTime)
{
    hammer->SetPosition(400.0f, 400.0f);
    hammer->Update(deltaTime);
    hammer->SetAnimation(static_cast<int>(AnimationSet::HAMMER));
    hammerCollision.UpdateBoundingBox(frameDimensions, false);
}

void Object::Draw() {
    hammer->Draw();
}

const CollisionManager& Object::GetCollisionManager() const
{
    return hammerCollision;
}

//different frames have different dimensions, so different hitbox
void Object::InitializeFrameDim()
{
    CSimpleSprite* temp = App::CreateSprite(HAMMER_SIZE_0.string().c_str(), 1, 1);
    frameDimensions[0] = { temp->GetHeight(),temp->GetWidth() };
    delete temp;

    temp=App::CreateSprite(HAMMER_SIZE_1_5.string().c_str(), 1, 1);
    frameDimensions[1] = { temp->GetHeight(),temp->GetWidth() };
    delete temp;

    temp = App::CreateSprite(HAMMER_SIZE_2_3_4.string().c_str(), 1, 1);
    frameDimensions[2] = { temp->GetHeight(),temp->GetWidth() };
    frameDimensions[3] = { temp->GetHeight(),temp->GetWidth() };
    frameDimensions[4] = { temp->GetHeight(),temp->GetWidth() };
    delete temp;

    temp = App::CreateSprite(HAMMER_SIZE_1_5.string().c_str(), 1, 1);
    frameDimensions[5] = { temp->GetHeight(),temp->GetWidth() };
    delete temp;

    temp = App::CreateSprite(HAMMER_SIZE_6.string().c_str(), 1, 1);
    frameDimensions[6] = { temp->GetHeight(),temp->GetWidth() };
    delete temp;

    temp = App::CreateSprite(HAMMER_SIZE_7.string().c_str(), 1, 1);
    frameDimensions[7] = { temp->GetHeight(),temp->GetWidth() };
    delete temp;
}
