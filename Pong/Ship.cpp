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

    m_vertices[0] = sf::Vector2f(0, 0);
    m_vertices[1] = sf::Vector2f(width, 0);
    m_vertices[2] = sf::Vector2f(width, height);
    m_vertices[3] = sf::Vector2f(0, height);

    acceleration = 20;
}

void Ship::update(float deltaTime)
{

}

Ship::~Ship(void)
{
}
