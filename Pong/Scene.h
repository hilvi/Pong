#include <vector>
#include "GameObject.h"

#pragma once
class Scene
{
private:
    std::vector<GameObject *> gameObjects;
    std::vector<GameObject *> destroyList;
public:
    Scene(void);

    const std::vector<GameObject *> &getGameObjects();
    const std::vector<GameObject *> &getDestroyList();
    void addObject(GameObject *obj);
    void destroyObject(GameObject *obj);
    void clean();
    virtual void nextLevel() {};
    virtual void update(float deltaTime) {};
    
    ~Scene(void);
};