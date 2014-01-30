#include "Pong.h"
#include "Paddle.h"
#include "Ball.h"
#include "Wall.h"
#include "GUI.h"
#include "EnemyPaddle.h"

Pong::Pong(void)
{
	Ball *ball = new Ball();
	addObject(ball);

	Paddle *paddle1 = new Paddle();
	paddle1->setPosition(580, 200);
	addObject(paddle1);

	EnemyPaddle *paddle2 = new EnemyPaddle(ball);
	paddle2->setPosition(10, 200);
	addObject(paddle2);

	Wall *wall1 = new Wall();
	wall1->setPosition(0, 10);
	addObject(wall1);

	Wall *wall2 = new Wall();
	wall2->setPosition(0, 380);
	addObject(wall2);

	GUI *gui = new GUI();
	gui->setPosition(300, 0);
	addObject(gui);
}


Pong::~Pong(void)
{
}
