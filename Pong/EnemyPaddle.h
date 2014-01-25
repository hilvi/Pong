#pragma once
#include "Paddle.h"
#include "Ball.h"

class EnemyPaddle : public Paddle
{
public:
	EnemyPaddle(Ball *ball);

	void update(float deltaTime);

	~EnemyPaddle();
private:
	Ball *ball;
};

