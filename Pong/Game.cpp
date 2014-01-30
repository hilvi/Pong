#include "Game.h"
#include "Pong.h"

Game::Game(sf::RenderWindow &win) : window(win)
{
	currentScene = new Pong();
}

void Game::checkCollisions()
{
	auto gameObjects = currentScene->getGameObjects();
	for(unsigned int i = 0; i < gameObjects.size(); i++) {
		for(unsigned int j = i+1; j < gameObjects.size(); j++) {
			GameObject *lhs = gameObjects[i];
			GameObject *rhs = gameObjects[j];

			if(lhs->getLeft() <= rhs->getRight() && rhs->getLeft() <= lhs->getRight() && lhs->getTop() <= rhs->getBottom() && rhs->getTop() <= lhs->getBottom()) {
				lhs->onCollision(rhs);
				rhs->onCollision(lhs);
			}
		}
	}
}

void Game::update(float deltaTime)
{
	auto gameObjects = currentScene->getGameObjects();
	checkCollisions();
	for(unsigned int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->update(deltaTime);
	}
}

void Game::draw()
{
	window.clear();

	auto gameObjects = currentScene->getGameObjects();
	for(unsigned int i = 0; i < gameObjects.size(); i++) {
		window.draw(*gameObjects[i]);
	}

    window.display();
}

Game::~Game(void)
{
	auto gameObjects = currentScene->getGameObjects();
	for(unsigned int i = 0; i < gameObjects.size(); i++) {
		delete gameObjects[i];
	}
}
