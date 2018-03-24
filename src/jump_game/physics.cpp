#include "jump_game/physics.h"
#include "jump_game/game_object_types.h"
#include "game_constants.h"

#include <iostream>
using namespace std;

using namespace GameConstants;
using namespace GameObjectTypes;

#include <iostream>
using namespace std;

void JumpBallPhysics::update ( Input *input ) {

    double offset = 0.0;

    if ( input -> left_key_down ) {
        offset -= 10;
    }
    if ( input -> right_key_down ) {
        offset += 10;
    }

    x += ( velocity.x * MS_PER_UPDATE + 0.5 * ( accel.x ) + MS_PER_UPDATE*MS_PER_UPDATE/1e6 ) + offset;
    y += ( velocity.y * MS_PER_UPDATE + 0.5 * ( accel.y ) + MS_PER_UPDATE*MS_PER_UPDATE/1e6 );

    velocity.x += ( accel.x ) * ( MS_PER_UPDATE );
    velocity.y += accel.y * MS_PER_UPDATE;
}

void JumpBallPhysics::onCollision ( Rect otherRect, Vec2d displ, int objectType ) {
    Rect ballRect = this->getRect();

    if ( objectType == GROUND ) {
        if ( velocity.y > 0 ) {
            velocity.y = -maxYVel;
        }
    }

    if ( objectType == TILE) {
        double cy = ( ballRect.y + ballRect.h );
        double ry = ( otherRect.y + 0.25 * otherRect.h );

        // Only reflect if colliding on way down.
        if ( velocity.y > 0 && cy < ry ) {
            velocity.y = -maxYVel;
        }

    }
}

void TilePhysics::update ( Input *input ) {
    Rect r = getRect();
    if ( r.x > SCREEN_WIDTH || r.y > SCREEN_HEIGHT ) {
        canBeDestroyed = true;
    }
}
