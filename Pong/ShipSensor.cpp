//
//  ShipSensor.cpp
//  engine
//
//  Created by Erkki Parkkulainen on 13/03/14.
//
//

#include "ShipSensor.h"
#include <iostream>

ShipSensor::ShipSensor(ShipAI *ai) : ai(ai) {
    
}

void ShipSensor::onCollision(GameObject *other) {
    if(other->getName() == "Asteroid")
        ai->incoming(other);
}

void ShipSensor::init() {
    float width = height = 300;
    
    parent->addCollider(width, height);
}

void ShipSensor::update(float deltaTime) {
    parent->setPosition(ai->getParent()->getPosition());
}