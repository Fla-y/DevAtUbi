#include "stdafx.h"
#include "App/app.h"
#include "Obstacle.h"

Obstacle::Obstacle(LogUtility& logger, AnimationManager& animManager, bool& isInitSuccessful, int& loopCounter,float& SCROLL_SPEED) :
    logger(logger), animManager(animManager),hammer(animManager.GetSprite(SpriteType::HAMMER)),
    hammerCollision(CollisionManager(hammer)),isActive(false), counter(loopCounter), copyCounter(0), scrollSpeed(SCROLL_SPEED)
{
    if (hammer == nullptr) {
        std::cerr << "Error: Failed to initialize hammer." << std::endl;
        logger.LogError("Hammer initialization failed.");
        bool isInitSuccesful = false;
    }
    InitializeFrameDim();
}

Obstacle::~Obstacle()
{
}

void Obstacle::Animate(float deltaTime)
{
    float x, y;
    hammer->GetPosition(x, y);
    float newX = x - (scrollSpeed * deltaTime);
    hammer->SetPosition(newX, y);
    hammer->Update(deltaTime);
    hammer->SetAnimation(static_cast<int>(AnimationSet::HAMMER));
    hammerCollision.UpdateBoundingBox(frameDimensions, false);
    //check if hammer is off screen
    if (newX + hammer->GetWidth() < 0) {
        RandomizeObstacle(y);
        counter++;
        copyCounter++;
        if (copyCounter >= 3) {
            scrollSpeed += 0.03f;
            copyCounter = 0;
            if (scrollSpeed > 1.6f)
                scrollSpeed = 1.6f;
        }
    }
}

void Obstacle::Draw() {
    hammer->Draw();
}

const CollisionManager& Obstacle::GetCollisionManager() const
{
    return hammerCollision;
}

//different frames have different dimensions
void Obstacle::InitializeFrameDim()
{
    CSimpleSpritePtr temp{ App::CreateSprite(HAMMER_SIZE_0.string().c_str(), 1, 1) };
    frameDimensions[0] = { temp->GetHeight(),temp->GetWidth() };

    temp.reset( App::CreateSprite(HAMMER_SIZE_1_5.string().c_str(), 1, 1));
    frameDimensions[1] = { temp->GetHeight(),temp->GetWidth() };

    temp.reset( App::CreateSprite(HAMMER_SIZE_2_3_4.string().c_str(), 1, 1));
    frameDimensions[2] = { temp->GetHeight(),temp->GetWidth() };
    frameDimensions[3] = { temp->GetHeight(),temp->GetWidth() };
    frameDimensions[4] = { temp->GetHeight(),temp->GetWidth() };

    temp.reset( App::CreateSprite(HAMMER_SIZE_1_5.string().c_str(), 1, 1));
    frameDimensions[5] = { temp->GetHeight(),temp->GetWidth() };

    temp.reset( App::CreateSprite(HAMMER_SIZE_6.string().c_str(), 1, 1));
    frameDimensions[6] = { temp->GetHeight(),temp->GetWidth() };

    temp.reset(App::CreateSprite(HAMMER_SIZE_7.string().c_str(), 1, 1));
    frameDimensions[7] = { temp->GetHeight(),temp->GetWidth() };
}

void Obstacle::RandomizeObstacle(float y) {
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(0, 8); 
    // Generate a random number between 0 and 8
    int randomNumber = distrib(gen);

    if (randomNumber == 5) {
        hammer->SetScale(5.0f);
        hammer->SetAngle(3.14159f);
        hammer->SetPosition(HAMMERX, 98.0f);
    }
    else if (randomNumber == 3) {
        hammer->SetScale(8.0f);
        hammer->SetAngle(0.0f);
        hammer->SetPosition(HAMMERX, 550.0f);
    }
    else {
        hammer->SetScale(3.0f);
        hammer->SetAngle(3.14159f);
        hammer->SetPosition(HAMMERX, 98.0f);
    }
}
