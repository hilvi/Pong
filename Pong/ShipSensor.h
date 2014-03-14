//
//  ShipSensor.h
//  engine
//
//  Created by Erkki Parkkulainen on 13/03/14.
//
//

#ifndef __engine__ShipSensor__
#define __engine__ShipSensor__

#include "Component.h"
#include "ShipAI.h"

class ShipAI;

class ShipSensor : public Component {
    ShipAI *ai;
public:
    ShipSensor(ShipAI *ai);
    void init();
    void onCollision(GameObject *other);
    void update(float deltaTime);
};

#endif /* defined(__engine__ShipSensor__) */
