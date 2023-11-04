#include "EnemyGhost.h"
EnemyGhost::EnemyGhost(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed)
	:animation(texture, imageCount, switchTime)
{
	this->speed = speed/1000;
	row = 2;
	faceRight = true;
	body.setSize(sf::Vector2f(140.0f, 140.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(0.0f, 0.0f);
	body.setTexture(texture);
}

EnemyGhost::~EnemyGhost() {}

void EnemyGhost::Update(float deltaTime, sf::Vector2f target) {
	sf::Vector2f EnemyPos = this->GetPosition();
	sf::Vector2f direction = (target - EnemyPos);
	if (direction.x -100 < EnemyPos.x) faceRight = false;
	else if (direction.x == 0.0f) {
		if (direction.y > EnemyPos.y) row = 1;
		else row = 0;
	}
	else faceRight = true;
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(deltaTime * speed * direction);
}

void EnemyGhost::Draw(sf::RenderWindow& window) {
	window.draw(body);
}