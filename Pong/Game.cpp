#include "Game.h"
#include "Pong.h"
#include "Breakout.h"

Scene *Game::currentScene = NULL;

Game::Game(sf::RenderWindow &win) : window(win)
{
    //currentScene = new Pong();
    currentScene = new Breakout();
}

void Game::checkCollisions()
{
    auto gameObjects = currentScene->getGameObjects();
    for(unsigned int i = 0; i < gameObjects.size(); i++) {
        Collider *lhs = gameObjects[i]->getCollider();
        if(lhs == NULL)
            continue;

        for(unsigned int j = i+1; j < gameObjects.size(); j++) {
            Collider *rhs = gameObjects[j]->getCollider();
            if(rhs == NULL)
                continue;

            if(lhs->getLeft() <= rhs->getRight() && rhs->getLeft() <= lhs->getRight() && lhs->getTop() <= rhs->getBottom() && rhs->getTop() <= lhs->getBottom()) {
                lhs->getParent()->onCollision(rhs->getParent());
                rhs->getParent()->onCollision(lhs->getParent());
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
    currentScene->clean();
}

void Game::draw()
{
    window.clear();

    auto gameObjects = currentScene->getGameObjects();
    for(unsigned int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->draw(window);
    }

    window.display();
}

Scene *Game::getCurrentScene()
{
    return currentScene;
}


Game::~Game(void)
{

}
