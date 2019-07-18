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

	bool jumpAllowed;

	State state;
	void updateSpeed(float dt, float maxSpeed);

	void setJumpAllowed(bool jumpAllowed);
public:

	Mario();
	~Mario();

	void update(float dt);

	void setState(State state);
	State getState();

	bool canJump();
};

