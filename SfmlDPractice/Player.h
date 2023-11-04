#pragma once
#include <SFML/Graphics.hpp>
#include "MyAnimation.h"
#include "Collider.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
private:
	sf::RectangleShape body;
	MyAnimation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};

