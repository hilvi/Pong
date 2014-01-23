#include "GameObject.h"


GameObject::GameObject(void)
{
}


void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(m_vertices, states);
}

float GameObject::getHeight()
{
	return height;
}

float GameObject::getWidth()
{
	return width;
}

float GameObject::getBottom() {
	return getPosition().y + height;
}

float GameObject::getTop() {
	return getPosition().y;
}

float GameObject::getLeft() {
	return getPosition().x;
}

float GameObject::getRight() {
	return getPosition().x + width;
}


void GameObject::onCollision(GameObject *collider)
{

}

void GameObject::update(float deltaTime)
{

}

GameObject::~GameObject(void)
{
}