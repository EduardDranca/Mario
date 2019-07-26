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
	//TODO:
	// refa tot ce tine de miscare si sarit si tot :(((

	//doar testare


	if (getPosition().y < 400.f)
	{
		auto speed = getSpeed();
		speed.y += 2000.f * dt;
		setSpeed(speed);
	}

	if (getPosition().y >= 400.f && getSpeed().y >= 0)
	{
		auto speed = getSpeed();
		speed.y = 0;
		setSpeed(speed);
		setPosition(sf::Vector2f(getPosition().x, 400.f));
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

		if (isMoving())
		{
			updateSpeed(dt, maxWalkingSpeed);
		}

		sf::Vector2f speed = getSpeed();
		std::cout << "speed: " << speed.x << ' ' << speed.y << std::endl;
	
		if (speed.y >= 0.f && getPosition().y >= 400.f)
		{
			speed.y = 0.f;
			setSpeed(speed);
			setPosition(sf::Vector2f(getPosition().x, 400.f));
			if (speed.x == 0)
			{
				setState(State::IDLE);
			}
			else
			{
				setState(State::WALKING);
			}
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
		auto speed = getSpeed();
		if (getDirection() == Dir::LEFT && speed.x > 0)
		{
			speed.x -= 2 * acceleration * dt;
		}
		if (getDirection() == Dir::RIGHT && speed.x < 0)
		{
			speed.x += 2 * acceleration * dt;
		}
		setSpeed(speed);
	}
	if (!isMoving() && state != State::IDLE)
	{
		std::cout << "Hey" << std::endl;
		sf::Vector2f speed = getSpeed();

		if (getDirection() == Dir::LEFT)
		{
			if (speed.x < 0)
			{
				if (state == State::JUMPING)
				{
					speed.x += acceleration * dt;
				}
				else
				{
					speed.x += 3 * acceleration * dt;	
				}
			}
			else
			{
				speed.x = 0;
				if (state != State::JUMPING)
				{
					setState(State::IDLE);
				}
			}
		}
		else
		{
			if (speed.x > 0)
			{
				if (state == State::JUMPING)
				{
					speed.x -= acceleration * dt;
				}
				else
				{
					speed.x -= 3 * acceleration * dt;
				}
			}
			else
			{
				speed.x = 0;
				if (state != State::JUMPING)
				{
					setState(State::IDLE);
				}
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
		setAnimationType(Animation::JUMP);
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

