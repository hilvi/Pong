/*
 * Copyright 2014 <copyright holder> <email>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "Asteroid.h"
#include "GameObject.h"
#include "Game.h"
#include "Math.h"

Asteroid::Asteroid(float angle)
{
    sf::Vector2f direction;
    direction.x = sinf(angle);
    direction.y = cosf(angle);

    tier = 1;
    this->angle = angle;
    speed = rand() % 10 + 5;
    speed /= 10;
    vSpeed = direction * speed;
}

Asteroid::Asteroid(float angle, int tier)
{
    sf::Vector2f direction;
    direction.x = sinf(angle);
    direction.y = cosf(angle);

    this->tier = tier;
    this->angle = angle;
    speed = rand() % 10 + 5;
    speed /= 10;
    vSpeed = direction * speed;
}

void Asteroid::init()
{
    width = 64 / tier;
    height = 64 / tier;

    parent->addCollider(width * 0.8f, height * 0.8f);

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    texture.loadFromFile("Asteroid.png");

    m_vertices[0].position = sf::Vector2f(0, 0);
    m_vertices[1].position = sf::Vector2f(width, 0);
    m_vertices[2].position = sf::Vector2f(width, height);
    m_vertices[3].position = sf::Vector2f(0, height);

    m_vertices[0].texCoords = sf::Vector2f(0, texture.getSize().y);
    m_vertices[1].texCoords = sf::Vector2f(0, 0);
    m_vertices[2].texCoords = sf::Vector2f(texture.getSize().x, 0);
    m_vertices[3].texCoords = sf::Vector2f(texture.getSize().x, texture.getSize().y);
}

void Asteroid::onCollision(GameObject *collider)
{
    if(collider->getName() == "Bullet") {
        Game::getCurrentScene()->destroyObject(parent);

        if(tier < 3) {
            tier++;
            GameObject *asteroid = new GameObject("Asteroid");
            asteroid->addComponent(new Asteroid(angle + 1.57f, tier));
            Game::getCurrentScene()->addObject(asteroid);
            asteroid->setPosition(parent->getPosition());

            asteroid = new GameObject("Asteroid");
            asteroid->addComponent(new Asteroid(angle - 1.57f, tier));
            Game::getCurrentScene()->addObject(asteroid);
            asteroid->setPosition(parent->getPosition());
        }
    }
}

void Asteroid::update(float deltatime)
{
    sf::Vector2f pos = parent->getPosition();
    float width = Game::getWindow().getSize().x;
    float height = Game::getWindow().getSize().y;

    //Wrap around screen
    if(pos.x < 0)
        pos.x = width;

    if(pos.x > width)
        pos.x = 0;

    if(pos.y < 0)
        pos.y = height;

    if(pos.y > height)
        pos.y = 0;

    parent->setPosition(pos);

    parent->move(vSpeed);
}
