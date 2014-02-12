#pragma once
#include "Paddle.h"
#include "Ball.h"

class EnemyPaddle : public Paddle
{
public:
	EnemyPaddle(GameObject *ball);

	void update(float deltaTime);

	~EnemyPaddle();
private:
	GameObject *ball;
};

