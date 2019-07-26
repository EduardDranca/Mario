#pragma once

#include <SFML/System/Vector2.hpp>

class BoundingBox
{
private:
	sf::Vector2f dimensions;
	sf::Vector2f position;
	sf::Vector2f origin;
public:

	bool checkCollision(const BoundingBox & box);



	BoundingBox();
	~BoundingBox();
};

