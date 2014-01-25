#include "Paddle.h"
#include "Ball.h"
#include "Game.h"
#include "Wall.h"
#include "GUI.h"
#include "EnemyPaddle.h"

Game::Game(sf::RenderWindow &win) : window(win)
{
	Ball *ball = new Ball();
	addObject(ball);

	Paddle *paddle1 = new Paddle();
	paddle1->setPosition(580, 200);
	addObject(paddle1);

	EnemyPaddle *paddle2 = new EnemyPaddle(ball);
	paddle2->setPosition(10, 200);
	addObject(paddle2);

	Wall *wall1 = new Wall();
	wall1->setPosition(0, 10);
	addObject(wall1);

	Wall *wall2 = new Wall();
	wall2->setPosition(0, 380);
	addObject(wall2);

	GUI *gui = new GUI();
	gui->setPosition(300, 0);
	addObject(gui);
}

void Game::checkCollisions()
{
	for(unsigned int i = 0; i < gameObjects.size(); i++) {
		for(unsigned int j = 0; j < gameObjects.size(); j++) {
			if(i == j)
				continue;
			GameObject *lhs = gameObjects[i];
			GameObject *rhs = gameObjects[j];

			if(lhs->getLeft() <= rhs->getRight() && rhs->getLeft() <= lhs->getRight() && lhs->getTop() <= rhs->getBottom() && rhs->getTop() <= lhs->getBottom()) {
				if (lhs->getLastCollision() != rhs) {
					lhs->onCollision(rhs);
					lhs->setLastCollision(rhs);
				}
			}
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
