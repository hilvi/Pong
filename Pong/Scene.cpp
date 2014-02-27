#include "Scene.h"

Scene::Scene(void)
{

}

void Scene::addObject(GameObject *obj)
{
    gameObjects.emplace_back(obj);
}

void Scene::destroyObject(GameObject *obj)
{
    destroyList.emplace_back(obj);
}

const std::vector<GameObject *> &Scene::getGameObjects()
{
    return gameObjects;
}

void Scene::clean()
{
    for(unsigned int i = 0; i < destroyList.size(); i++) {
        GameObject *tmp = destroyList[i];
        gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), tmp), gameObjects.end());
        destroyList.erase(std::remove(destroyList.begin(), destroyList.end(), tmp), destroyList.end());
        delete tmp;
    }
}

Scene::~Scene(void)
{
    for(unsigned int i = 0; i < gameObjects.size(); i++) {
        delete gameObjects[i];
    }
}
