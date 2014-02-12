#include "Scene.h"

Scene::Scene(void)
{

}

void Scene::addObject(GameObject *obj)
{
    gameObjects.emplace_back(obj);
}

const std::vector<GameObject *> &Scene::getGameObjects() {
    return gameObjects;
}

Scene::~Scene(void)
{
    for(unsigned int i = 0; i < gameObjects.size(); i++) {
        delete gameObjects[i];
    }
}
