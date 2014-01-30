#include "GameObject.h"

#pragma once
class Wall : public GameObject
{
public:
	Wall(std::string name, float width, float height);
	~Wall(void);
};

