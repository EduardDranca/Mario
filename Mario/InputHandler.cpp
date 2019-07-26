#include "InputHandler.h"
#include "MoveCommand.h"
#include "JumpCommand.h"
#include "StopMovingCommand.h"

InputHandler::~InputHandler()
{
}

void InputHandler::handleInput(const sf::Event & event)
{
	//TODO: adauga un map in care sa tii actiunile impreuna cu tastele corespunzatoare
	switch (event.type)
	{
	case sf::Event::KeyPressed:
	{
		switch (event.key.code)
		{
		case sf::Keyboard::A:
		{
			MoveCommand command(mario, Direction::LEFT);
			command.execute();
			break;
		}
		case sf::Keyboard::D:
		{
			MoveCommand command(mario, Direction::RIGHT);
			command.execute();
			break;
		}
		case sf::Keyboard::Space:
		{
			JumpCommand command(mario);
			command.execute();
			break;
		}
		}
		break;
	}
	case sf::Event::KeyReleased:
	{
		switch (event.key.code)
		{
		case sf::Keyboard::A:
		{
			StopMovingCommand command(mario, Direction::LEFT);
			command.execute();
			break;
		}
		case sf::Keyboard::D:
		{
			StopMovingCommand command(mario, Direction::RIGHT);
			command.execute();
			break;
		}
		}
		break;
	}
	default:
	{
		return;
	}
	}
}
