#pragma once
#include <SFML/Graphics.hpp>
class MyAnimation
{
public:
	MyAnimation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
	~MyAnimation();

	void Update(int row, float deltaTime, bool faceRight);

public:
	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	//speed
	float totalTime;
	float switchTime;
};

