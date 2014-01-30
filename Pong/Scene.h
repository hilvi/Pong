#include <vector>
#include "GameObject.h"

#pragma once
class Scene
{
private:
	std::vector<GameObject *> gameObjects;
public:
	Scene(void);

	const std::vector<GameObject *> &getGameObjects();
	void addObject(GameObject *obj);

	~Scene(void);
};

