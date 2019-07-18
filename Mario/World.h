#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Mario.h"
class World
{
private:
	float groundLevel;
	float gravity;

	sf::RenderWindow gameWindow;
	sf::Clock gameClock;

	void update(float dt);

	Mario player;
public:
	World();
	~World();
};

