#include "Wall.h"

Wall::Wall(void)
{
	name = "Wall";
	width = 600;
	height = 10;

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(4);
	
	m_vertices[0] = sf::Vector2f(0, 0);
	m_vertices[1] = sf::Vector2f(width, 0);
	m_vertices[2] = sf::Vector2f(width, height);
	m_vertices[3] = sf::Vector2f(0, height);
}


Wall::~Wall(void)
{
}
