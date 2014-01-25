#include "GameObject.h"

#pragma once
class Paddle : public GameObject
{
protected:
	int speed;
public:
	Paddle(void);
	~Paddle(void);

	virtual void update(float deltaTime);
};

