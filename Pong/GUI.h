#pragma once
#include "gameobject.h"
class GUI :
	public GameObject
{
public:
	GUI(void);
	~GUI(void);
private:
	sf::Text text;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

