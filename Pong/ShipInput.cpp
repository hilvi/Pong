//
//  ShipInput.cpp
//  engine
//
//  Created by Erkki Parkkulainen on 13/03/14.
//
//

#include "ShipInput.h"

ShipInput::ShipInput(Ship *ship) : ship(ship)
{

}


void ShipInput::update(float deltaTime)
{
    //Input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        ship->turn(-1);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        ship->turn(1);

    if(sf::Keyboard::isKeyPressed((sf::Keyboard::Up))) {
        ship->accelerate();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        ship->shoot();
    }
}
