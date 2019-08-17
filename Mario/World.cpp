#include "World.h"

#include <SFML/Window/Event.hpp>

bool World::initialized = false;
World * World::instance = nullptr;


void World::update(float dt)
{
}

void World::run()
{
	gameClock.restart();

	while (gameWindow.isOpen())
	{
		sf::Event event;

		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
			else
			{
				inputHandler.handleInput(event);
			}
		}

		gameWindow.clear();
		player.draw(gameWindow);
		gameWindow.display();
		player.update(gameClock.getElapsedTime().asSeconds());
		gameClock.restart();
	}
}

World * World::getInstance()
{
	if (!initialized)
	{
		initialized = true;
		instance = new World();
	}

	return instance;
}

Mario & World::getPlayer()
{
	return player;
}

World::~World()
{
}
