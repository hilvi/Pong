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
}
