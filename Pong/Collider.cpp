#include "Collider.h"
#include "GameObject.h"

Collider::Collider(float width, float height)
{
    this->width = width;
    this->height = height;
    parent = NULL;
}


float Collider::getHeight()
{
    return height;
}

float Collider::getWidth()
{
    return width;
}

sf::Vector2f Collider::getCenter()
{
    return parent->getPosition();
}

float Collider::getBottom()
{
    return parent->getPosition().y + height / 2;
}

float Collider::getTop()
{
    return parent->getPosition().y - height / 2;
}

float Collider::getLeft()
{
    return parent->getPosition().x - width / 2;
}

float Collider::getRight()
{
    return parent->getPosition().x + width / 2;
}

GameObject *Collider::getParent()
{
    return parent;
}

void Collider::setParent(GameObject *parent)
{
    this->parent = parent;
}
