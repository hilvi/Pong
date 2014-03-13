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
    parent = NULL;
    collider = NULL;
}

GameObject::GameObject(std::string name, GameObject *parent) : name(name), parent(parent)
{
    collider = NULL;
}

GameObject::~GameObject()
{
    for(auto & comp : components) {
        delete comp;
    }

    delete collider;
}

void GameObject::draw(sf::RenderWindow &window)
{
    for(auto & comp : components) {
        window.draw(*comp);
    }
}

void GameObject::update(float deltatime)
{
    for(auto & comp : components) {
        comp->update(deltatime);
    }
}

void GameObject::addComponent(Component *comp)
{
    comp->setParent(this);
    components.emplace_back(comp);
    comp->init();
}

void GameObject::addCollider(float width, float height)
{
    this->setOrigin(width / 2, height / 2);
    collider = new Collider(width, height);
    collider->setParent(this);
}

Collider *GameObject::getCollider()
{
    if(collider != NULL) {
        return collider;
    } else if(parent != NULL) {
        return parent->getCollider();
    } else {
        return NULL;
    }
}

void GameObject::onCollision(GameObject *collider)
{
    for(auto & comp : components) {
        comp->onCollision(collider);
    }
}

sf::Transform GameObject::getCombinedTransform()
{
    if(parent != NULL) {
        return getTransform() * parent->getCombinedTransform();
    } else {
        return getTransform();
    }
}

const std::vector<Component *> &GameObject::getComponents()
{
    return components;
}

std::string GameObject::getName()
{
    return name;
}

GameObject *GameObject::getParent()
{
    return parent;
}
void GameObject::setParent(GameObject *p)
{
    parent = p;
}
