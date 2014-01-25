#include "EnemyPaddle.h"
#include "Ball.h"


EnemyPaddle::EnemyPaddle(Ball *ball) : Paddle()
{
	this->ball = ball;
}

void EnemyPaddle::update(float deltaTime)
{
	float direction = (ball->getTop() + ball->getBottom()) / 2 - (this->getTop() + this->getBottom()) / 2;
	direction = direction < 0 ? -1 : 1;
	
	if (this->getTop() + direction*speed*deltaTime > 20 && this->getBottom() + direction*speed*deltaTime < 380)
		move(0, direction*speed*deltaTime);
}

EnemyPaddle::~EnemyPaddle()
{
}
