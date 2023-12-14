#include "stdafx.h"
#include "Physics.h"
#include "stdafx.h"

void Physics::ApplyGravity(float& positionY, float& velocityY, float deltaTime, float gravity) {
    velocityY += gravity * deltaTime;
    positionY += velocityY * deltaTime;

    // Clamp position to prevent falling through the floor
    if (positionY < 50.0f) {
        positionY = 50.0f;
        velocityY = 0.0f;
    }
}
