#pragma once

#include "game_constants.h"
#include "game_object/game_object.h"
#include "jump_game/game_object_types.h"
#include "math/geometry.h"

#include <iostream>
using namespace std;

using namespace GameConstants;
using namespace GameObjectTypes;

//TODO(chesetti): Abstract this into a class.
void handleCollisions ( GameObject **gameObjects ) {
    // TODO(chesetti): Optimize this.
    for ( int i=0; i < MAX_GAME_OBJECTS; i++ ) {
        for ( int j=i+1; j < MAX_GAME_OBJECTS; j++ ) {
            GameObject *obj1 = gameObjects[i];
            GameObject *obj2 = gameObjects[j];
            if ( obj1 == NULL || obj1->canBeDestroyed() ) continue;
            if ( obj2 == NULL || obj2->canBeDestroyed() ) continue;

            Rect r1 = obj1->getPhysics()->getRect();
            Rect r2 = obj2->getPhysics()->getRect();

            if ( !isRectIntersect ( r1, r2 ) ) {
                continue;
            }
            
            obj1->getPhysics()->onCollision(r2, Vec2d(0,0) /* Displacement Vector */, obj2->getObjectType());
            obj2->getPhysics()->onCollision(r1, Vec2d(0,0) /* Displacement Vector */, obj1->getObjectType());

        }
    }
}
