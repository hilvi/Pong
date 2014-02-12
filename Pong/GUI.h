#pragma once
#include "Component.h"

class GUI :
	public Component
{
public:
	GUI(void);
	~GUI(void);
private:
	sf::Text text;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

