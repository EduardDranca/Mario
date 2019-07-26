#pragma once
#include "Command.h"
class JumpCommand :
	public Command
{
public:
	JumpCommand(Mario * mario) : Command(mario) {}
	~JumpCommand();

	void execute();
};

