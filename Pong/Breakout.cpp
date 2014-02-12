/*
 * Copyright 2014 <copyright holder> <email>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "Breakout.h"
#include "Paddle.h"
#include "Ball.h"
#include "Wall.h"
#include "Brick.h"

Breakout::Breakout()
{
    GameObject *ball = new GameObject("Ball");
    ball->addComponent(new Ball());
    ball->addCollider(10, 10);
    addObject(ball);

    GameObject *paddle1 = new GameObject("Paddle");
    paddle1->addComponent(new Paddle);
    paddle1->setPosition(580, 200);
    paddle1->addCollider(10, 30);
    addObject(paddle1);

    GameObject *wall1 = new GameObject("HWall");
    wall1->addComponent(new Wall("HWall", 600, 10));
    wall1->addCollider(600, 10);
    wall1->setPosition(10, 10);
    addObject(wall1);

    GameObject *wall2 = new GameObject("HWall");
    wall2->addComponent(new Wall("HWall", 600, 10));
    wall2->addCollider(600, 10);
    wall2->setPosition(10, 380);
    addObject(wall2);

    GameObject *wall3 = new GameObject("VWall");
    wall3->addComponent(new Wall("VWall", 10, 360));
    wall3->addCollider(10, 360);
    wall3->setPosition(10, 20);
    addObject(wall3);
    
    GameObject *brick = new GameObject("Brick");
    brick->addComponent(new Brick());
    brick->addCollider(10, 200);
    brick->setPosition(250, 50);
    addObject(brick);
}
