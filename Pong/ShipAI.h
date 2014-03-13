//
//  ShipAI.h
//  engine
//
//  Created by Erkki Parkkulainen on 13/03/14.
//
//

#ifndef __engine__ShipAI__
#define __engine__ShipAI__

#include "Component.h"
#include "Ship.h"
#include "GameObject.h"

class ShipAI : public Component {
private:
    Ship *ship;
public:
    ShipAI(Ship *ship);
    void update(float deltaTime);
    void init();
};

#endif /* defined(__engine__ShipAI__) */
