#include "StopMovingCommand.h"


StopMovingCommand::~StopMovingCommand()
{
}

void StopMovingCommand::execute()
{
	auto mario = getReceiver();
	if (direction == mario->getDirection())
	{
		mario->setMoving(false);
	}
}
