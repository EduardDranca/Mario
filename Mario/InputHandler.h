#pragma once

#include "SFML/Window/Event.hpp"
#include "Mario.h"

class InputHandler
{
private:
	Mario * mario;
public:
	InputHandler() : mario(nullptr) {}
	InputHandler(Mario * mario) : mario(mario) {}
	~InputHandler();

	void setReceiver(Mario * mario);
	void handleInput(const sf::Event & event);
};

