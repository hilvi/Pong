#include "Pong.h"
#include "Paddle.h"
#include "Ball.h"
#include "Wall.h"
#include "GUI.h"
#include "EnemyPaddle.h"

Pong::Pong(void)
{
    GameObject *ball = new GameObject("Ball");
    ball->addComponent(new Ball());
    ball->addCollider(10, 10);
    addObject(ball);

    GameObject *paddle1 = new GameObject("Paddle");
    paddle1->addComponent(new Paddle);
    paddle1->setPosition(580, 200);
    paddle1->addCollider(10, 30);
    addObject(paddle1);

    GameObject *paddle2 = new GameObject("Paddle");
    paddle2->addComponent(new EnemyPaddle(ball));
    paddle2->setPosition(10, 200);
    paddle2->addCollider(10, 30);
    addObject(paddle2);

    GameObject *wall1 = new GameObject("HWall");
    wall1->addComponent(new Wall("HWall", 600, 10));
    wall1->addCollider(600, 10);
    wall1->setPosition(0, 10);
    addObject(wall1);

    GameObject *wall2 = new GameObject("HWall");
    wall2->addComponent(new Wall("HWall", 600, 10));
    wall2->addCollider(600, 10);
    wall2->setPosition(0, 380);
    addObject(wall2);

    GameObject *gui = new GameObject("GUI");
    gui->addComponent(new GUI);
    gui->setPosition(300, 0);
    addObject(gui);
}


Pong::~Pong(void)
{
}
