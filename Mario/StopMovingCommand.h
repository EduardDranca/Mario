#pragma once
#include "Command.h"
class StopMovingCommand :
	public Command
{
private:
	Direction direction;
public:
	StopMovingCommand(Mario * mario, Direction direction) : Command(mario), direction(direction) {}
	~StopMovingCommand();

	void execute();
};

