#include "JumpCommand.h"

JumpCommand::~JumpCommand()
{
}

void JumpCommand::execute()
{
	auto mario = getReceiver();

	if (mario->canJump())
	{
		mario->setState(Mario::State::JUMPING);
		auto speed = mario->getSpeed();
		speed.y = -400.f;
		mario->setSpeed(speed);
	}
}
