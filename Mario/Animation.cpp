#include "Animation.h"

#include "Utils.h"

#include <iostream>

void Animation::update(float dt)
{
	float frameTime = 1.f / frameRate;
	currentFrameTime += dt;

	if (currentFrameTime >= frameTime)
	{
		currentFrameTime -= frameTime;
		currentFrame++;

		if (currentFrame >= numberOfFrames)
		{
			currentFrame = 0;
		}

		sprite.setTextureRect(frameRectangles[currentFrame]);
		sprite.setOrigin(spriteOrigins[currentFrame]);
	}
}

void Animation::draw(sf::RenderWindow & renderWindow)
{
	renderWindow.draw(sprite);
}

void Animation::setFlipped(bool flipped)
{
	this->flipped = flipped;

	if (flipped)
	{
		sprite.setScale(sf::Vector2f(-1.f, 1.f));
	}
	else
	{
		sprite.setScale(sf::Vector2f(1.f, 1.f));
	}
}

void Animation::setFrameRate(int frameRate)
{
	this->frameRate = frameRate;
}

void Animation::setPosition(const sf::Vector2f & position)
{
	sprite.setPosition(position);
}

void Animation::setNumberOfFrames(int numberOfFrames)
{
	this->numberOfFrames = numberOfFrames;
	frameRectangles.resize(numberOfFrames);
	spriteOrigins.resize(numberOfFrames);
}

void Animation::addFrame(const sf::IntRect & frame, const sf::Vector2f & origin, int index)
{
	frameRectangles[index] = frame;
	spriteOrigins[index] = origin;
}

int Animation::getFrameRate()
{
	return frameRate;
}

int Animation::getNumberOfFrames()
{
	return numberOfFrames;
}

Animation::Animation()
{
	currentFrame = 0;
	currentFrameTime = 0;
}

Animation::Animation(const Animation & animation) : texture(animation.texture)
{
	frameRate = animation.frameRate;
	currentFrame = animation.currentFrame;
	numberOfFrames = animation.numberOfFrames;
	frameRectangles = animation.frameRectangles;
	spriteOrigins = animation.spriteOrigins;
	texture = animation.texture;
	sprite = animation.sprite;
	sprite.setTexture(*texture);
	sprite.setTextureRect(frameRectangles[currentFrame]);
	sprite.setOrigin(spriteOrigins[currentFrame]);
}

Animation::Animation(sf::Texture * texture) : texture(texture)
{
	currentFrame = 0;
	currentFrameTime = 0.f;
	sprite.setTexture(*(this->texture));
}


Animation::~Animation()
{
}

Animation & Animation::operator=(const Animation & animation)
{
	frameRate = animation.frameRate;
	currentFrame = animation.currentFrame;
	numberOfFrames = animation.numberOfFrames;
	frameRectangles = animation.frameRectangles;
	spriteOrigins = animation.spriteOrigins;
	texture = animation.texture;
	sprite = animation.sprite;
	sprite.setTexture(*texture);
	sprite.setTextureRect(frameRectangles[currentFrame]);
	sprite.setOrigin(spriteOrigins[currentFrame]);
	
	return *this;
}
