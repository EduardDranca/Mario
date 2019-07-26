#include "Command.h"

void Command::setReceiver(Mario * mario)
{
	this->mario = mario;
}

Mario * Command::getReceiver()
{
	return mario;
}
