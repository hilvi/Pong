//
//  ShipAI.cpp
//  engine
//
//  Created by Erkki Parkkulainen on 13/03/14.
//
//

#include "ShipAI.h"
#include "ShipSensor.h"
#include "Game.h"
#include "Math.h"

#include <iostream>

ShipAI::ShipAI(Ship *ship) : ship(ship) {

}

void ShipAI::init() {
    avoiding = false;
    distanceToCurrent = 4096;
    aiTimer = aiTimerTime = 1;
}

void ShipAI::update(float deltaTime) {
    aiTimer -= deltaTime;
    if(aiTimer < 0) {
        if(avoiding) {
            ship->accelerate();
            avoiding = false;
            distanceToCurrent = 4096;
        }
        aiTimer = aiTimerTime;
    }
    ship->shoot();
}

void ShipAI::incoming(GameObject *asteroid) {
    sf::Vector2f distance = asteroid->getPosition() - parent->getPosition();
    if(avoiding) {
        if(Math::magnitude(distance) < distanceToCurrent) {
            distanceToCurrent = Math::magnitude(distance);
            angleToCurrent = atan2f(distance.y, distance.x);
        }
    } else {
        distanceToCurrent = Math::magnitude(distance);
        angleToCurrent = atan2f(distance.y, distance.x);
    }
    
    avoiding = true;
    float angle = angleToCurrent * 180 / 3.14159;
    if(angle < 0) angle += 360;
    std::cout << angle << " : " << parent->getRotation() << std::endl;

    //parent->setRotation(angleToCurrent * 180 / 3.14159);
    if(angle < parent->getRotation())
        ship->turn(-1);
    else
        ship->turn(1);
}