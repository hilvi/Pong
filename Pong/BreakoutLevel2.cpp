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

#include "BreakoutLevel2.h"
#include "BreakoutLevel1.h"
#include "Game.h"

BreakoutLevel2::BreakoutLevel2() : Breakout()
{
    int bricks = 3;
    int spacing = 50;
    int position = 100;

    for(int i = 0; i < bricks; i++) {
        GameObject *brick = new GameObject("Brick");
        brick->addComponent(new Brick(3));
        brick->setPosition(100, position);
        addObject(brick);
        position += spacing;
    }
}

void BreakoutLevel2::nextLevel()
{
    Game::loadScene(new BreakoutLevel1);
}
