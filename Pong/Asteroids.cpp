#include "Asteroids.h"
#include "Ship.h"

Asteroids::Asteroids(void)
{
    GameObject *ship = new GameObject("Ship");
    ship->addComponent(new Ship());
    ship->setPosition(300, 200);
    addObject(ship);
}


Asteroids::~Asteroids(void)
{
}
