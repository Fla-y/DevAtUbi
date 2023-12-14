#ifndef PHYSICS_H
#define PHYSICS_H

#include "stdafx.h"
#include "app/app.h"

class Physics {
public:
    static void ApplyGravity(float& positionY, float& velocityY, float deltaTime, float gravity);
};

#endif 

