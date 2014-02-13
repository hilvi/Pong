/*
 * Copyright 2014 <copyright holder> <email>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "Collider.h"
#include <vector>
#include "Component.h"
#include <string>

class Component;

class GameObject : public sf::Transformable
{
private:
    GameObject *parent = NULL;
    Collider *collider = NULL;
    std::vector<Component *> components;

protected:
    std::string name;
public:
    GameObject(std::string name);
    GameObject(const GameObject &other);
    GameObject(std::string name,  GameObject *parent);
    ~GameObject();

    Collider *getCollider();
    virtual void update(float deltaTime);
    virtual void draw(sf::RenderWindow &window);
    std::string getName();
    virtual void onCollision(GameObject *collider);
    sf::Transform getCombinedTransform();
    void addComponent(Component *comp);
    void addCollider(float width, float height);
};

#endif // GAMEOBJECT_H
