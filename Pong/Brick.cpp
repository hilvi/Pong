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

#include "Brick.h"
#include "Game.h"
#include "Breakout.h"

int Brick::_lives = 0;

Brick::Brick(int lives) : lives(lives)
{
    _lives += lives;
}

void Brick::init()
{
    width = 10;
    height = 40;

    parent->addCollider(width, height);

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    m_vertices[0] = sf::Vector2f(0, 0);
    m_vertices[1] = sf::Vector2f(width, 0);
    m_vertices[2] = sf::Vector2f(width, height);
    m_vertices[3] = sf::Vector2f(0, height);

    float colorRatio = lives / 3.0f;
    color = sf::Color(255 * colorRatio, 0, 0);
    setColor(color);
}

void Brick::setColor(sf::Color color)
{
    for(unsigned int i = 0; i < m_vertices.getVertexCount(); i++) {
        m_vertices[i].color = color;
    }
}

void Brick::onCollision(GameObject *collider)
{
    lives--;
    float colorRatio = lives / 3.0f;
    color = sf::Color(255 * colorRatio, 0, 0);
    setColor(color);

    if(lives == 0) {

        Game::getCurrentScene()->destroyObject(parent);
    }

    if(--_lives == 0) {
        Game::getCurrentScene()->nextLevel();
    }
}
