#include "Scene.h"

Scene::Scene(void)
{

}

void Scene::addObject(GameObject *obj)
{
    gameObjects.emplace_back(obj);
}

void Scene::destroyObject(GameObject* obj)
{
  destroyList.emplace_back(obj);
}

const std::vector<GameObject *> &Scene::getGameObjects() {
    return gameObjects;
}

void Scene::clean() {
    for(unsigned int i = 0; i < destroyList.size(); i++) {
        gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), destroyList[i]), gameObjects.end());
	delete destroyList[i];
    }
    destroyList.clear();
}

Scene::~Scene(void)
{
    for(unsigned int i = 0; i < gameObjects.size(); i++) {
        delete gameObjects[i];
    }
}
