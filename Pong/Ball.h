#include "Component.h"

#pragma once
class Ball : public Component
{
public:
    sf::Vector2f velocity;

    Ball(void);

    void init();
    void update(float deltaTime);
    void reset(int direction);

    void onCollision(GameObject *collider);

    void paddleCollision(const sf::Vector2f &paddle);

    ~Ball(void);
private:
    float speed;
};

