#include <iostream>

#include <SFML/Graphics.hpp>

#include "Mario.h"
#include "InputHandler.h"

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

	Mario mario;
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

	sf::Clock clk;

	InputHandler inputHandler(&mario);

	while (gameWindow.isOpen())
	{
		sf::Event event;

		while (gameWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				gameWindow.close();
				break;
			/*case sf::Event::KeyPressed:
			{
				if (event.key.code == sf::Keyboard::A)
				{
					if (mario.getState() == Mario::State::IDLE)
						mario.setState(Mario::State::WALKING);
					mario.setMoving(true);
					mario.setDirection(Character::Dir::LEFT);
				}
				else if (event.key.code == sf::Keyboard::D)
				{
					if (mario.getState() == Mario::State::IDLE)
						mario.setState(Mario::State::WALKING);
					mario.setMoving(true);
					mario.setDirection(Character::Dir::RIGHT);
				}
				if (event.key.code == sf::Keyboard::W && mario.canJump())
				{
					mario.setState(Mario::State::JUMPING);
				}
				break;
			}
			case sf::Event::KeyReleased:
			{
				if (event.key.code == sf::Keyboard::A && mario.getDirection() == Character::Dir::LEFT)
				{
					mario.setMoving(false);
				}
				else if (event.key.code == sf::Keyboard::D && mario.getDirection() == Character::Dir::RIGHT)
				{
					mario.setMoving(false);
				}
				break;
			}*/
			}
			inputHandler.handleInput(event);
		}
		gameWindow.clear(sf::Color::Black);
		mario.draw(gameWindow);
		gameWindow.display();
		mario.update(clk.getElapsedTime().asSeconds());

		clk.restart();
	}
}