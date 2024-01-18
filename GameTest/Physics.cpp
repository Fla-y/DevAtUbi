#include "stdafx.h"
#include "Physics.h"
#include "stdafx.h"

float Physics::Gravity(float deltaTime, float& velocityY)
{
    velocityY -= GRAVITY * deltaTime;
    return velocityY;

}
