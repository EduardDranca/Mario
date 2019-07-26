#include "MoveCommand.h"

MoveCommand::~MoveCommand()
{
}

void MoveCommand::execute()
{
	auto mario = getReceiver();

	if (mario->getState() == Mario::State::IDLE)
	{
		mario->setState(Mario::State::WALKING);
	}
	mario->setMoving(true);
	mario->setDirection(direction);
}
