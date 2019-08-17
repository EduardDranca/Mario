#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "InputHandler.h"
#include "Mario.h"


#define TheWorld World::getInstance()

class World
{
private:
	World() : inputHandler(&player), gameWindow(sf::VideoMode(640, 480), "Mario")
	{
		gameWindow.setFramerateLimit(60);
	}

	static World *instance;
	static bool initialized;

	float groundLevel;
	float gravity;

	sf::RenderWindow gameWindow;
	sf::Clock gameClock;

	Mario player;

	InputHandler inputHandler;
public:
	void update(float dt);
	void run();

	static World * getInstance();

	Mario & getPlayer();
	~World();
};

