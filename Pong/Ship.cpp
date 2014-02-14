#include "Ship.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "Game.h"
#include "Math.h"

#include <iostream>


const float PI = 3.14159265358979f;

Ship::Ship(void)
{
}

void Ship::init()
{
    width = 30;
    height = 30;

    parent->addCollider(width, height);

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    texture.loadFromFile("Ship.png");

    m_vertices[0].position = sf::Vector2f(0, 0);
    m_vertices[1].position = sf::Vector2f(width, 0);
    m_vertices[2].position = sf::Vector2f(width, height);
    m_vertices[3].position = sf::Vector2f(0, height);

    m_vertices[0].texCoords = sf::Vector2f(0, height);
    m_vertices[1].texCoords = sf::Vector2f(0, 0);
    m_vertices[2].texCoords = sf::Vector2f(width, 0);
    m_vertices[3].texCoords = sf::Vector2f(width, height);

    acceleration = 5;
    drag = 1;
    rotateSpeed = 200;
    maxSpeed = 100;

    parent->setOrigin(getCollider()->getCenter());
}

void Ship::update(float deltaTime)
{
    sf::Vector2f pos = parent->getPosition();
    float width = Game::getWindow().getSize().x;
    float height = Game::getWindow().getSize().y;

    if(pos.x < 0)
        pos.x = width;

    if(pos.x > width)
        pos.x = 0;

    if(pos.y < 0)
        pos.y = height;

    if(pos.y > height)
        pos.y = 0;

    parent->setPosition(pos);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        parent->rotate(-rotateSpeed * deltaTime);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        parent->rotate(rotateSpeed * deltaTime);

    if(sf::Keyboard::isKeyPressed((sf::Keyboard::Up))) {
        speed.x += acceleration * deltaTime * cos(parent->getRotation() * PI / 180);
        speed.y += acceleration * deltaTime * sin(parent->getRotation() * PI / 180);
    }

    sf::Vector2f dir = Math::normalize(speed);

    if(Math::magnitude(speed) > maxSpeed)
        speed = dir * maxSpeed;

    speed -= dir * drag * deltaTime;

    parent->move(speed);
}


Ship::~Ship(void)
{
}
