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

#include "Component.h"

Component::Component()
{

}

Component::~Component()
{

}

Collider *Component::getCollider()
{
    return parent->getCollider();
}

float Component::getHeight()
{
    return height;
}

float Component::getWidth()
{
    return width;
}

std::string Component::getName()
{
    return name;
}

void Component::setParent(GameObject *parent)
{
    this->parent = parent;
}

void Component::init()
{

}

void Component::onCollision(GameObject *collider)
{

}

void Component::update(float deltatime)
{

}

void Component::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= parent->getCombinedTransform();

    states.texture = &texture;

    target.draw(m_vertices, states);
}

Component *Component::clone()
{
    return new Component(*this);
}