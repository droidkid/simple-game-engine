#include "engine/collisions.h"
#include "engine/game_engine_constants.h"
#include "math/geometry.h"

using namespace GameEngineConstants;

void handleCollisions ( GameObject **gameObjects ) {
    for ( int i=0; i < MAX_GAME_OBJECTS; i++ ) {
        for ( int j=i+1; j < MAX_GAME_OBJECTS; j++ ) {
            GameObject *obj1 = gameObjects[i];
            GameObject *obj2 = gameObjects[j];
            if ( obj1 == NULL || obj1->isDestroyed() ) continue;
            if ( obj2 == NULL || obj2->isDestroyed() ) continue;

            Rect r1 = obj1->getPhysics()->getRect();
            Rect r2 = obj2->getPhysics()->getRect();

            if ( !isRectIntersect ( r1, r2 ) ) {
                continue;
            }

            obj1->getPhysics()->onCollision(obj2->getPhysics(), obj2->getObjectType());
            obj2->getPhysics()->onCollision(obj1->getPhysics(), obj1->getObjectType());

        }
    }
}
