#include "Component.h"

#pragma once
class Ship : public Component
{
protected:
    float acceleration;
    float rotateSpeed;
    float maxSpeed;
    float drag;
    sf::Vector2f speed;
public:
    Ship(void);
    ~Ship(void);

    virtual void update(float deltaTime);
    virtual void init();
};

