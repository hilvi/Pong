//
//  ShipAI.cpp
//  engine
//
//  Created by Erkki Parkkulainen on 13/03/14.
//
//

#include "ShipAI.h"
#include "Game.h"


ShipAI::ShipAI() {
    GameObject *sensor = new GameObject("Sensor");
    sensor->addComponent(new ShipSensor(this));
    Game::getCurrentScene()->addObject(sensor);
}

void ShipAI::update(float deltaTime) {
    
}