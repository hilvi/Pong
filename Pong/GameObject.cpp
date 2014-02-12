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

#include "GameObject.h"

GameObject::GameObject(std::string name) : name(name)
{
  
}

GameObject::GameObject(std::string name, GameObject *parent) : name(name), parent(parent)
{

}

GameObject::GameObject(const GameObject& other)
{

}

GameObject::~GameObject()
{
  for(int i = 0; i < components.size(); i++) {
    delete components[i];
  }
}

void GameObject::draw(sf::RenderWindow &window)
{
  for(int i = 0; i < components.size(); i++) {
    window.draw(*components[i]);
  }
}

void GameObject::update(float deltatime)
{
  for(int i = 0; i < components.size(); i++) {
    components[i]->update(deltatime);
  }
}

void GameObject::addComponent(Component* comp)
{
  comp->setParent(this);
  components.emplace_back(comp);
  comp->init();
}

void GameObject::addCollider(float width, float height)
{
  collider = new Collider(width, height);
  collider->setParent(this);
}

Collider* GameObject::getCollider()
{
  if(collider != NULL)
    return collider;
  else if(parent != NULL)
    return parent->getCollider();
  else
    return NULL;
}

void GameObject::onCollision(GameObject *collider) {
  for(int i = 0; i < components.size(); i++) {
    components[i]->onCollision(collider);
  }
}

sf::Transform GameObject::getCombinedTransform()
{
   if(parent != NULL)
        return getTransform() * parent->getCombinedTransform();
    else
        return getTransform();
}

std::string GameObject::getName() {
  return name;
}

