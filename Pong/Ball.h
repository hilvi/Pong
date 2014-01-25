#include "GameObject.h"

#pragma once
class Ball : public GameObject
{
public:
	sf::Vector2f velocity;

	Ball(void);

	void update(float deltaTime);
	void reset(int direction);

	void onCollision(GameObject *collider);

	~Ball(void);
private:
	float speed;
};
