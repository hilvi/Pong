#include "Paddle.h"


Paddle::Paddle(void)
{

}

void Paddle::init() {
    name = "Paddle";
    width = 10;
    height = 30;

    parent->addCollider(width, height);

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    m_vertices[0] = sf::Vector2f(0, 0);
    m_vertices[1] = sf::Vector2f(width, 0);
    m_vertices[2] = sf::Vector2f(width, height);
    m_vertices[3] = sf::Vector2f(0, height);

    speed = 150;
}

void Paddle::update(float deltaTime) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (this->getCollider()->getTop() - speed*deltaTime > 20)
            parent->move(0, -speed*deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (this->getCollider()->getBottom() + speed*deltaTime < 380)
            parent->move(0, speed*deltaTime);
    }
}

Paddle::~Paddle(void)
{
}
