#include "breakout/ball.h"
#include "game_constants.h"

using namespace GameConstants;

void BallPhysics::update() {
    if ( x <= 0 && xvel < 0 ) {
        xvel = -xvel;
    }
    if ( x + w >= SCREEN_WIDTH && xvel > 0 ) {
        xvel = -xvel;
    }
    if ( y <= 0 && yvel < 0 ) {
        yvel = -yvel;
    }
    if ( y >= SCREEN_HEIGHT && yvel > 0 ) {
        yvel = -yvel;
    }
    x += xvel;
    y += yvel;
}
