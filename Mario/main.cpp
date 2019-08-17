#include <iostream>

#include <SFML/Graphics.hpp>

#include "InputHandler.h"
#include "Mario.h"
#include "World.h"

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(640, 480), "Mario");
	gameWindow.setFramerateLimit(60);

	sf::Texture t;
	t.loadFromFile("mario_spritesheet.png");

	Animation a(&t);
	a.setNumberOfFrames(2);
	a.addFrame(sf::IntRect(6, 8, 12, 15), sf::Vector2f(6, 14), 0);
	a.addFrame(sf::IntRect(34, 8, 15, 16), sf::Vector2f(8, 15), 1);
	a.setFrameRate(20);

	Mario & mario = TheWorld->getPlayer();
	mario.addAnimation(a, Animation::WALK);

	Animation b(&t);
	b.setNumberOfFrames(1);
	b.addFrame(sf::IntRect(6, 8, 12, 15), sf::Vector2f(6, 14), 0);
	b.setFrameRate(1);
	mario.addAnimation(b, Animation::IDLE);

	Animation c(&t);
	c.setNumberOfFrames(1);
	c.addFrame(sf::IntRect(94, 8, 16, 16), sf::Vector2f(8, 15), 0);
	c.setFrameRate(1);
	mario.addAnimation(c, Animation::JUMP);

	mario.setPosition(sf::Vector2f(100.f, 100.f));

	TheWorld->run();
}