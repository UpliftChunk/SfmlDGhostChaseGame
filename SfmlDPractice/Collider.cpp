#include "Collider.h"

Collider::Collider(sf::RectangleShape& body)
:body(body){

}

Collider::~Collider() {
} 

bool Collider::CheckCollision(Collider& object, float push) {

	sf::Vector2f objectPosition = object.GetPosition();
	sf::Vector2f objectHalfSize = object.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = objectPosition.x - this->GetPosition().x ;
	float deltaY = objectPosition.y - this->GetPosition().y ;

	float intersectX = abs(deltaX) + 50.0f - (objectHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) + 50.0f - (objectHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (abs(intersectX) > abs(intersectY)) {
			if (deltaX > 0.0f) {
				Move(intersectX * (1.0f - push), 0.0f);
				object.Move(-intersectX * push, 0.0f);
			}
			else {
				Move(-intersectX * (1.0f - push), 0.0f);
				object.Move(intersectX * push, 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				Move(0.0f, intersectY * (1.0f - push));
				object.Move(0.0f, -intersectY * push);
			}
			else {
				Move(0.0f, -intersectY * (1.0f - push));
				object.Move( 0.0f, intersectY * push);
			}
		}

		return true;
	}

	return false;
}