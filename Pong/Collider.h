#ifndef _COLLIDER
#define _COLLIDER

#include "GameObject.h"

class GameObject;

class Collider {
private:
    float width;
    float height;
    GameObject *parent = NULL;
public:
    Collider(float width, float height);
    bool checkCollision(Collider collider);

    float getLeft();
    float getTop();
    float getRight();
    float getBottom();
    float getWidth();
    float getHeight();
    sf::Vector2f getCenter();
    GameObject *getParent();
    void setParent(GameObject *parent);
};


#endif
