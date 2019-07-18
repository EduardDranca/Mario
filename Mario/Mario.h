#pragma once

#include "Character.h"

class Mario : public Character
{
public:
	enum State
	{
		IDLE,
		WALKING,
		RUNNING,
		SWIMMING,
		JUMPING
	};

private:
	float acceleration;
	float maxWalkingSpeed;
	float maxSwimmingSpeed;
	float maxRunningSpeed;
	float jumpingSpeed;

	State state;
	void updateSpeed(float dt, float maxSpeed);
public:

	Mario();
	~Mario();

	void update(float dt);

	void setState(State state);
	State getState();
};

