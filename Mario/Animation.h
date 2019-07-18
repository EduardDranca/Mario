#pragma once

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Animation
{
private:
	sf::Texture * texture;
	sf::Sprite sprite;

	bool flipped;
	int frameRate;
	int currentFrame;
	int numberOfFrames;
	float currentFrameTime;
	std::vector<sf::IntRect> frameRectangles;
	std::vector<sf::Vector2f> spriteOrigins;
public:
	enum
	{
		IDLE = 0,
		WALK,
		RUN,
		JUMP,
		SWIM,
		DIE
	};

	void update(float dt);
	void draw(sf::RenderWindow & renderWindow);

	void setFlipped(bool flipped = false);
	void setFrameRate(int frameRate);
	void setPosition(const sf::Vector2f & position);
	void setNumberOfFrames(int numberOfFrames);
	void addFrame(const sf::IntRect & frame, const sf::Vector2f & origin, int index);

	int getFrameRate();
	int getNumberOfFrames();

	Animation();
	Animation(const Animation & animation);
	Animation(sf::Texture * texture);
	~Animation();

	Animation & operator= (const Animation & animation);
};

