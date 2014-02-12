#include "Component.h"

#pragma once
class Paddle : public Component
{
protected:
	int speed;
public:
	Paddle(void);
	~Paddle(void);

	virtual void update(float deltaTime);
};

