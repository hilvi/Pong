#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"

#pragma once
class Game
{
private:
	sf::RenderWindow &window;
public:
	float deltaTime;

	std::vector<GameObject *> gameObjects;

	Game(sf::RenderWindow &window);

	void update(float deltaTime);
	void draw();
	void checkCollisions();
	
	void addObject(GameObject *obj);

	~Game(void);
};

