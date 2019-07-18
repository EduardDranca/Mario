#pragma once
#include <map>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Animation.h"

class Character
{
public:
	enum Dir
	{
		LEFT,
		RIGHT	
	};
private:
	sf::Vector2f speed;
	sf::Vector2f position;
	bool moving;
	bool directionChanged;
	Dir direction;

	int currentAnimationType;
	std::map<int, Animation> animations;
public:
	Character();
	virtual ~Character();

	virtual void draw(sf::RenderWindow & renderWindow);
	virtual void update(float dt);
	virtual void move(const sf::Vector2f & offset);

	void setSpeed(const sf::Vector2f & speed);
	void setPosition(const sf::Vector2f & position);
	void setAnimationType(int animation);
	void setMoving(bool moving);
	void setDirection(Dir direction);
	void updatePosition(float dt);

	sf::Vector2f getSpeed();
	sf::Vector2f getPosition();
	int getAnimationType();
	bool isMoving();
	Dir getDirection();

	Animation & getAnimation();

	void addAnimation(const Animation & animation, int type);
};

