#ifndef PHYSICS_H
#define PHYSICS_H

static constexpr float GRAVITY = 9.8f;  // Standard gravity value

class Physics {
public:
	static float Gravity(float deltaTime, float& velocityY);
};

#endif 

