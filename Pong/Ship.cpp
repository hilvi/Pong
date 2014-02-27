#include "Ship.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "Game.h"
#include "Math.h"
#include "Bullet.h"
#include "Asteroids.h"

const float PI = 3.14159265358979f;

Ship::Ship(void)
{
}

void Ship::init()
{
    name = "Ship";
    width = 32;
    height = 32;

    parent->addCollider(width, height);

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    texture.loadFromFile("Ship.png");

    m_vertices[0].position = sf::Vector2f(0, 0);
    m_vertices[1].position = sf::Vector2f(width, 0);
    m_vertices[2].position = sf::Vector2f(width, height);
    m_vertices[3].position = sf::Vector2f(0, height);

    m_vertices[0].texCoords = sf::Vector2f(0, texture.getSize().y);
    m_vertices[1].texCoords = sf::Vector2f(0, 0);
    m_vertices[2].texCoords = sf::Vector2f(texture.getSize().x, 0);
    m_vertices[3].texCoords = sf::Vector2f(texture.getSize().x, texture.getSize().y);

    acceleration = 5;
    drag = 1;
    rotateSpeed = 200;
    maxSpeed = 100;
    coolDown = 0.3f;
    coolDownTimer = 0;

    parent->setOrigin(getCollider()->getCenter());
}

void Ship::update(float deltaTime)
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
    
    
    //Movement
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
    
    
    //Shooting
    coolDownTimer -= deltaTime;
    
    if(coolDownTimer < 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        sf::Vector2f direction;
        direction.x = cos(parent->getRotation() * PI / 180);
        direction.y = sin(parent->getRotation() * PI / 180);
        
        GameObject *bullet = new GameObject("Bullet");
        bullet->addComponent(new Bullet(direction));
        Game::getCurrentScene()->addObject(bullet);
        
        bullet->setPosition(parent->getPosition());
        coolDownTimer = coolDown;
    }
}

void Ship::onCollision(GameObject *collider)
{
    if(collider->getName() == "Asteroid") {
        //Game::loadScene(new Asteroids());
    }
}

Ship *Ship::clone()
{
    return new Ship(*this);
}

Ship::~Ship(void)
{
}
