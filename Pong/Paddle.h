#include "GameObject.h"
#include <iostream>

#pragma once
class Paddle : public GameObject
{
private:
	int speed;
public:
	Paddle(void);
	~Paddle(void);

	void update(float deltaTime);

	void onCollision(GameObject *collider)
	{
		std::cout << "foo" << std::endl;
	}
};

