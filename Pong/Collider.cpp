#include "Collider.h"

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
    sf::Vector2f center;
    center.x = (getLeft() + getRight()) / 2;
    center.y = (getTop() + getBottom()) / 2;

    return center;
}

float Collider::getBottom()
{
    return parent->getPosition().y + height;
}

float Collider::getTop()
{
    return parent->getPosition().y;
}

float Collider::getLeft()
{
    return parent->getPosition().x;
}

float Collider::getRight()
{
    return parent->getPosition().x + width;
}

GameObject *Collider::getParent()
{
    return parent;
}

void Collider::setParent(GameObject *parent)
{
    this->parent = parent;
}
