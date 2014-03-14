//
//  ShipInput.h
//  engine
//
//  Created by Erkki Parkkulainen on 13/03/14.
//
//

#ifndef __engine__ShipInput__
#define __engine__ShipInput__

#include "Component.h"
#include "Ship.h"

class ShipInput : public Component
{
private:
    Ship *ship;
public:
    ShipInput(Ship *ship);
    void update(float deltaTime);
};

#endif /* defined(__engine__ShipInput__) */
