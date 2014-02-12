#include "Ball.h"
#include <cmath>
#include <cstdlib>
#include "Game.h"

const float PI=3.14159265358979f;

Ball::Ball(void)
{

}

void Ball::init() {
    width = 10;
    height = 10;

    parent->addCollider(width, height);
    
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    m_vertices[0] = sf::Vector2f(0, 0);
    m_vertices[1] = sf::Vector2f(width, 0);
    m_vertices[2] = sf::Vector2f(width, height);
    m_vertices[3] = sf::Vector2f(0, height);

    speed = 200;

    reset(1);
}

void Ball::update(float deltaTime) {
    parent->move(velocity.x*deltaTime, velocity.y*deltaTime);
    if(parent->getPosition().x < 0) {
        //player won
        reset(1);
    }
    if(parent->getPosition().x > 600) {
        //enemy won
        reset(-1);
    }
}

void Ball::onCollision(GameObject *collider)
{
    /*if(getLastCollision() == collider)
    	return;*/
    if(collider->getName() == "Paddle") {
        paddleCollision(collider->getCollider()->getCenter());
    } else if(collider->getName() == "HWall") {
        velocity.y = -velocity.y;
    } else if(collider->getName() == "VWall") {
      velocity.x = -velocity.x;
    } else if(collider->getName() == "Brick") {
      Game::getCurrentScene()->destroyObject(collider);
      velocity.x = -velocity.x;
    }
    //setLastCollision(collider);
}

void Ball::paddleCollision(const sf::Vector2f &paddle) {
    sf::Vector2f ball = this->getCollider()->getCenter();

    sf::Vector2f distance = ball - paddle;

    float angle = atan2f(distance.y, distance.x);

    velocity.x = cosf(angle)*speed;
    velocity.y = sinf(angle)*speed;
}

void Ball::reset(int direction)
{
    parent->setPosition(300, 200);

    int x = rand() % (int)(speed/4) + speed*3/4;
    int y = (int)sqrtf(speed*speed - x*x);

    velocity.x = (float)direction * x;
    direction = rand() % 2 == 0 ? -1 : 1;
    velocity.y = (float)direction * y;

    //setLastCollision(NULL);
}

Ball::~Ball(void)
{
}
