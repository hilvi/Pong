#include "Paddle.h"
#include "Ball.h"
#include "Game.h"

Game::Game(sf::RenderWindow &win) : window(win)
{
	Paddle *paddle1 = new Paddle();
	paddle1->setPosition(10, 200);
	addObject(paddle1);

	Ball *ball = new Ball();
	addObject(ball);
}

void Game::checkCollisions()
{
	for(unsigned int i = 0; i < gameObjects.size(); i++) {
		for(unsigned int j = 0; j < gameObjects.size(); j++) {
			if(i == j)
				continue;
			GameObject *lhs = gameObjects[i];
			GameObject *rhs = gameObjects[j];

			if(lhs->getRight() < rhs->getLeft() && lhs->getRight() > lhs->getLeft() && lhs->getBottom() < lhs->getTop() && lhs->getTop() > lhs->getBottom())
				lhs->onCollision(rhs);
		}
	}
}

void Game::update(float deltaTime)
{
	checkCollisions();
	for(unsigned int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->update(deltaTime);
	}
}

void Game::draw()
{
	window.clear();

	for(unsigned int i = 0; i < gameObjects.size(); i++) {
		window.draw(*gameObjects[i]);
	}

    window.display();
}

void Game::addObject(GameObject *obj)
{
	gameObjects.push_back(obj);
}

Game::~Game(void)
{
}
