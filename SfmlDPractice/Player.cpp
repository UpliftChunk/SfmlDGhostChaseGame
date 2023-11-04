#include "Player.h"
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) 
:animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(180.0f, 180.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(-490.0f, -490.0f);
	body.setTexture(texture);
}

Player::~Player() {}

/* void Player::SetallowedMovement(sf::Vector2f& movement) {
	float deltaX = objectPositionX[i] - this->GetPosition().x;
	float deltaY = objectPositionY[i] - this->GetPosition().y;

	float intersectX = abs(deltaX) - (objectHalfsize[i].x + this->HalfPosition().x);
	float intersectY = abs(deltaY) - (objectHalfsize[i].y + this->HalfPosition().y);

	if (intersectX < 0 && intersectY < 0)
		movement.x = 0, movement.y = 0;
} */
void Player::Update(float deltaTime) {
	sf::Vector2f movement(0.0f, 0.0f);
	faceRight = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{movement.x -= speed * deltaTime; row = 1;}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{movement.x += speed * deltaTime; row = 2;}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{movement.y += speed * deltaTime; row = 0;}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{movement.y -= speed * deltaTime; row = 3;}
	
	if (movement.x == 0.0f && movement.y == 0.0f) row = 4;
	else if(movement.x){
		if (movement.x < 0.0f) { row = 1; }
		else { row = 2; }
	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	//SetallowedMovement(movement);
	body.move(movement);
}

void Player::Draw(sf::RenderWindow &window) {
	window.draw(body);
}