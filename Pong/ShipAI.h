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
#include "ShipSensor.h"

class ShipAI : public Component {
private:
    ShipSensor *sensor;
public:
    ShipAI();
    void update(float deltaTime);
};

#endif /* defined(__engine__ShipAI__) */
