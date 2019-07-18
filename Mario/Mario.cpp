#include "Mario.h"

#include <iostream>
#include "Utils.h"


Mario::Mario()
{
	acceleration = 600.f;
	maxWalkingSpeed = 600.f;
	maxRunningSpeed = 1000.f;
}


Mario::~Mario()
{
}

void Mario::update(float dt)
{
	//doar testare
	if (getPosition().y == 100.f)
	{
		setJumpAllowed(true);
	}

	switch (state)
	{
	case State::IDLE:
	{
		break;
	}
	case State::WALKING:
	{
		if (isMoving())
		{
			updateSpeed(dt, maxWalkingSpeed);
		}
		break;
	}
	case State::RUNNING:
	{
		if (isMoving())
		{
			updateSpeed(dt, maxRunningSpeed);
		}
		break;
	}
	case State::JUMPING:
	{
		//doar pentru testare
		sf::Vector2f speed = getSpeed();

		if (getPosition().y < 100.f)
		{
			std::cout << "speed: " << speed.y << std::endl;
			speed.y += 1000.f * dt;
			setSpeed(speed);
		}
		else if (speed.y >= 0.f)
		{
			speed.y = 0.f;
			setSpeed(speed);
			setPosition(sf::Vector2f(getPosition().x, 100.f));
			setState(State::IDLE);
		}
	}
	case State::SWIMMING:
	{
		break;
	}
	}

	getAnimation().update(dt);
	
	//TODO: muta tot intr-o singura functie
	if (isMoving())
	{
		sf::Vector2f speed = getSpeed();

		if (getDirection() == Dir::LEFT)
		{
			if (speed.x > 0)
			{
				speed.x -= 3 * acceleration * dt;
			}
		}
		else
		{
			if (speed.x < 0)
			{
				speed.x += 3 * acceleration * dt;
			}
		}
		setSpeed(speed);
	}

	if (!isMoving() && state != State::IDLE)
	{
		sf::Vector2f speed = getSpeed();

		if (getDirection() == Dir::LEFT)
		{
			if (speed.x < 0)
			{
				speed.x += 3 * acceleration * dt;
			}
			else
			{
				speed.x = 0;
				setState(State::IDLE);
			}
		}
		else
		{
			if (speed.x > 0)
			{
				speed.x -= 3 * acceleration * dt;
			}
			else
			{
				speed.x = 0;
				setState(State::IDLE);
			}
		}
		setSpeed(speed);
	}

	updatePosition(dt);
}

void Mario::setState(State state)
{
	this->state = state;
	switch (state)
	{
	case WALKING:
		setAnimationType(Animation::WALK);
		setMoving(true);
		break;
	case RUNNING:
		setAnimationType(Animation::RUN);
		setMoving(true);
		break;
	case SWIMMING:
		setAnimationType(Animation::SWIM);
		setMoving(true);
		break;
	case JUMPING:
		setJumpAllowed(false);
		setSpeed(sf::Vector2f(getSpeed().x, -100.f));
		setAnimationType(Animation::IDLE);
		setMoving(true);
		break;
	case IDLE:
		setAnimationType(Animation::IDLE);
		setMoving(false);
		break;
	}
}

Mario::State Mario::getState()
{
	return state;
}

bool Mario::canJump()
{
	return jumpAllowed;
}

void Mario::updateSpeed(float dt, float maxSpeed)
{
	sf::Vector2f speed = getSpeed();
	std::cout << speed.x << std::endl;
	if (getDirection() == Character::Dir::LEFT)
	{
		speed.x -= acceleration * dt;
	}
	else
	{
		speed.x += acceleration * dt;
	}

	clamp(-maxSpeed, maxSpeed, speed.x);
	setSpeed(speed);
}

void Mario::setJumpAllowed(bool jumpAllowed)
{
	this->jumpAllowed = jumpAllowed;
}

