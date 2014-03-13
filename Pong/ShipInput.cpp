//
//  ShipInput.cpp
//  engine
//
//  Created by Erkki Parkkulainen on 13/03/14.
//
//

#include "ShipInput.h"

ShipInput::ShipInput(Ship *ship) : ship(ship) {
    
}


void ShipInput::update(float deltaTime) {
    //Input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        ship->turn(-1, deltaTime);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        ship->turn(1, deltaTime);
    
    if(sf::Keyboard::isKeyPressed((sf::Keyboard::Up))) {
        ship->accelerate(deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        ship->shoot(deltaTime);
    }
}