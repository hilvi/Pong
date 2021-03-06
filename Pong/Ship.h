#include "Component.h"

#pragma once
class Ship : public Component
{
protected:
    float acceleration;
    float delta;
    float rotateSpeed;
    float maxSpeed;
    float drag;
    float coolDown;
    float coolDownTimer;
    sf::Vector2f speed;
    GameObject *bullet;
public:
    Ship(void);
    ~Ship(void);

    virtual void update(float deltaTime);
    virtual void init();
    virtual void onCollision(GameObject *collider);

    void turn(float direction);
    void accelerate();
    void shoot();
};

