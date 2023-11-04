
#include <SFML/Graphics.hpp>
#include "MyAnimation.h"
#include "Collider.h"
class EnemyGhost
{
public:
	EnemyGhost(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~EnemyGhost();

	void Update(float deltaTime, sf::Vector2f target);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
private:
	sf::RectangleShape body;
	MyAnimation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};
