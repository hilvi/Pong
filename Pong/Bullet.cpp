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

#include "Bullet.h"
#include "GameObject.h"
#include "Game.h"

#include <iostream>

Bullet::Bullet(sf::Vector2f dir)
{
    speed = 5;
    direction = speed * dir;
}

void Bullet::init()
{
    name = "Bullet";
    width = 2;
    height = 2;

    parent->addCollider(width, height);

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    m_vertices[0].position = sf::Vector2f(0, 0);
    m_vertices[1].position = sf::Vector2f(width, 0);
    m_vertices[2].position = sf::Vector2f(width, height);
    m_vertices[3].position = sf::Vector2f(0, height);

    color = sf::Color::White;
}

void Bullet::onCollision(GameObject *collider)
{
    if(collider->getName() == "Asteroid")
        Game::getCurrentScene()->destroyObject(parent);
}

void Bullet::update(float deltatime)
{
    sf::Vector2f pos = parent->getPosition();
    float width = Game::getWindow().getSize().x;
    float height = Game::getWindow().getSize().y;

    color.a -= deltatime;
    setColor(color);

    if(color.a == 0)
        Game::getCurrentScene()->destroyObject(parent);

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

    parent->move(direction);
}


void Bullet::setColor(sf::Color color)
{
    for(unsigned int i = 0; i < m_vertices.getVertexCount(); i++) {
        m_vertices[i].color = color;
    }
}
