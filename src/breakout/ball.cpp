#include "breakout/ball.h"
#include "game_constants.h"

using namespace GameConstants;

void BallPhysics::update(Input *input) {
    if ( x <= 0 && velocity.x < 0 ) {
        velocity.x = -velocity.x;
    }
    if ( x + w >= SCREEN_WIDTH && velocity.x > 0 ) {
        velocity.x = -velocity.x;
    }
    if ( y <= 0 && velocity.y < 0 ) {
        velocity.y = -velocity.y;
    }
    if ( y >= SCREEN_HEIGHT && velocity.y > 0 ) {
        velocity.y = -velocity.y;
    }
    x += velocity.x;
    y += velocity.y;
}
