#include <SFML/Graphics.hpp>
#include <string>

#pragma once
class GameObject : public sf::Drawable, public sf::Transformable
{
public:
	GameObject(void);

	virtual void update(float deltaTime);
	float getWidth();
	float getHeight();

	float getLeft();
	float getTop();
	float getRight();
	float getBottom();

	virtual void onCollision(GameObject *collider);

	~GameObject(void);
protected:
	std::string name;
	float width, height;
	sf::VertexArray m_vertices;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

