#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include "Scene.h"

#pragma once
class Game
{
private:
	sf::RenderWindow &window;
	Scene *currentScene;
public:
	float deltaTime;

	Game(sf::RenderWindow &window);

	void update(float deltaTime);
	void draw();
	void checkCollisions();

	~Game(void);
};

