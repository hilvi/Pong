#include "Ball.h"
#include <cmath>


Ball::Ball(void)
{
	width = 10;
	height = 10;

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(4);
	
	m_vertices[0] = sf::Vector2f(0, 0);
	m_vertices[1] = sf::Vector2f(width, 0);
	m_vertices[2] = sf::Vector2f(width, height);
	m_vertices[3] = sf::Vector2f(0, height);

	reset();
}

void Ball::update(float deltaTime) {
	move(velocity.x*deltaTime, velocity.y*deltaTime);
	if(getPosition().x < 0) {
		//player won
		reset();
	}
	if(getPosition().x > 600) {
		//enemy won
		reset();
	}
}

void Ball::reset()
{
	setPosition(300, 200);

	velocity.x = -100;
	velocity.y = -20;
}

Ball::~Ball(void)
{
}
