#pragma once
#include "Command.h"

class MoveCommand : public Command
{
private:
	Direction direction;
public:
	MoveCommand(Mario * mario, Direction direction) : Command(mario), direction(direction) {}
	~MoveCommand();

	void execute();
};

