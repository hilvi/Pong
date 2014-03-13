//
//  ShipSensor.cpp
//  engine
//
//  Created by Erkki Parkkulainen on 13/03/14.
//
//

#include "ShipSensor.h"


ShipSensor::ShipSensor(ShipAI *ai) : ai(ai) {
    
}

void ShipSensor::init() {
    float width = height = 100;
    
    parent->addCollider(width, height);
}