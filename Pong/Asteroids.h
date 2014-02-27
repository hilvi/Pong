#pragma once
#include "Scene.h"

class Asteroids : public Scene
{
private:
    float spawnTimer;
    float spawnTime;
    GameObject *ship;
    float minDistance;
public:
    Asteroids(void);
    ~Asteroids(void);
    
    void update(float deltaTime);
};

