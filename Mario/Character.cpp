#include "Character.h"
#include "Utils.h"

#include <iostream>


Character::Character()
{
}

Character::~Character()
{

}

void Character::draw(sf::RenderWindow & renderWindow)
{
	animations[currentAnimationType].setFlipped(flipped);
	animations[currentAnimationType].setPosition(position);
	animations[currentAnimationType].draw(renderWindow);
}

void Character::update(float dt)
{
	animations[currentAnimationType].update(dt);
}

void Character::move(const sf::Vector2f & offset)
{
	setPosition(position + offset);
}

void Character::setSpeed(const sf::Vector2f & speed)
{
	this->speed = speed;
}

void Character::setPosition(const sf::Vector2f & position)
{
	this->position = position;
	this->animations[currentAnimationType].setPosition(position);
}

void Character::setAnimationType(int animation)
{
	currentAnimationType = animation;
}

void Character::setMoving(bool moving)
{
	this->moving = moving;
}

void Character::setDirection(Dir direction)
{
	if (this->direction != direction)
	{
		this->direction = direction;
		if (direction == Dir::RIGHT)
		{
			setFlipped(true);
		}
		else
		{
			setFlipped(false);
		}
	}
}

void Character::setFlipped(bool flipped)
{
	this->flipped = flipped;
}

void Character::updatePosition(float dt)
{
	setPosition(position + speed * dt);
}

sf::Vector2f Character::getSpeed()
{
	return speed;
}

sf::Vector2f Character::getPosition()
{
	return position;
}

int Character::getAnimationType()
{
	return currentAnimationType;
}

bool Character::isMoving()
{
	return moving;
}

bool Character::getFlipped()
{
	return flipped;
}

Character::Dir Character::getDirection()
{
	return direction;
}

Animation & Character::getAnimation()
{
	return animations[currentAnimationType];
}

void Character::addAnimation(const Animation & animation, int type)
{
	animations[type] = animation;
}
