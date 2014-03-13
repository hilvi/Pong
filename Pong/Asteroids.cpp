#include "Asteroids.h"
#include "Ship.h"
#include "ShipInput.h"
#include "Asteroid.h"
#include "Game.h"
#include "Math.h"
#include <cstdlib>
#include <cmath>

#include <iostream>

Asteroids::Asteroids(void)
{
    spawnTimer = spawnTime = 3;
    minDistance = 200;

    ship = new GameObject("Ship");
    Ship *shipComp = new Ship();
    ship->addComponent(shipComp);
    ship->addComponent(new ShipInput(shipComp));
    ship->setPosition(300, 200);
    addObject(ship);
}

void Asteroids::update(float deltaTime)
{
    spawnTimer -= deltaTime;

    if(spawnTimer < 0) {
        sf::Vector2f shipPos = ship->getPosition();
        int width = Game::getWindow().getSize().x;
        int height = Game::getWindow().getSize().y;

        sf::Vector2f asteroidPos(rand() % width, rand() % height);

        sf::Vector2f distance = asteroidPos - shipPos;
        float angle = atan2f(distance.y, distance.x);
        sf::Vector2f direction;
        direction.x = sinf(angle);
        direction.y = cosf(angle);

        if(Math::magnitude(distance) < minDistance) {
            asteroidPos = direction * minDistance;
        }

        spawnTimer = spawnTime;
        GameObject *asteroid = new GameObject("Asteroid");
        asteroid->addComponent(new Asteroid(angle));
        asteroid->setPosition(asteroidPos);
        addObject(asteroid);
    }
}

Asteroids::~Asteroids(void)
{
}
