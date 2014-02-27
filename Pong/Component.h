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

#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <string>

class GameObject;
class Collider;

class Component : public sf::Drawable
{
public:
    Component();
    ~Component();
    Collider *getCollider();
    virtual void init();
    virtual void onCollision(GameObject *collider);
    virtual void update(float deltatime);
    void setParent(GameObject *parent);
    float getWidth();
    float getHeight();
    std::string getName();
protected:
    std::string name;
    GameObject *parent;
    float width, height;
    sf::VertexArray m_vertices;
    sf::Texture texture;
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif // COMPONENT_H
