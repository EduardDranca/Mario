#pragma once

#include "Mario.h"

using Direction = Character::Dir;

class Command
{
private:
	Mario * mario;
public:
	Command(Mario * mario) : mario(mario) {}
	virtual ~Command() {}

	void setReceiver(Mario * mario);
	Mario* getReceiver();

	virtual void execute() = 0;
};

