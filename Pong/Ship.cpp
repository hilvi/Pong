#include "Ship.h"

#include <iostream>

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

    m_vertices[0].texCoords = sf::Vector2f(0, 0);
    m_vertices[1].texCoords = sf::Vector2f(width, 0);
    m_vertices[2].texCoords = sf::Vector2f(width, height);
    m_vertices[3].texCoords = sf::Vector2f(0, height);

    acceleration = 20;
}

void Ship::update(float deltaTime)
{

}

Ship::~Ship(void)
{
}
