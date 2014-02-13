#include "EnemyPaddle.h"
#include "Ball.h"


EnemyPaddle::EnemyPaddle(GameObject *ball) : Paddle()
{
    this->ball = ball;
}

void EnemyPaddle::update(float deltaTime)
{
    float direction = (ball->getCollider()->getTop() + ball->getCollider()->getBottom()) / 2 - (this->getCollider()->getTop() + this->getCollider()->getBottom()) / 2;
    direction = direction < 0 ? -1.0f : 1.0f;

    if(this->getCollider()->getTop() + direction * speed * deltaTime > 20 && this->getCollider()->getBottom() + direction * speed * deltaTime < 380) {
        parent->move(0, direction * speed * deltaTime);
    }
}

EnemyPaddle::~EnemyPaddle()
{
}
