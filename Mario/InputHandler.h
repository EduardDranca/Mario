#pragma once

#include "SFML/Window/Event.hpp"
#include "Mario.h"

class InputHandler
{
private:
	Mario * mario;
public:
	InputHandler(Mario * mario) : mario(mario) {}
	~InputHandler();

	void handleInput(const sf::Event & event);
};

