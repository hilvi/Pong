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
	std::string getName();
	float getLeft();
	float getTop();
	float getRight();
	float getBottom();
	GameObject *getLastCollision();
	void setLastCollision(GameObject *);

	virtual void onCollision(GameObject *collider);

	~GameObject(void);
protected:
	std::string name;
	float width, height;
	sf::VertexArray m_vertices;
	GameObject *lastCollision;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

