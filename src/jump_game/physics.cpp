#include "jump_game/physics.h"
#include "game_constants.h"

#include <iostream>
using namespace std;

using namespace GameConstants;

void JumpBallPhysics::update() {
    
    
    x += (velocity.x * MS_PER_UPDATE + 0.5 * accel.x + MS_PER_UPDATE*MS_PER_UPDATE/1e6);
    y += (velocity.y * MS_PER_UPDATE + 0.5 * accel.y + MS_PER_UPDATE*MS_PER_UPDATE/1e6);
    
    velocity.x += accel.x * MS_PER_UPDATE;
    velocity.y += accel.y * MS_PER_UPDATE;
}

void JumpBallPhysics::onCollision(Rect rect, Vec2d displ) {
    if (velocity.y > 0) {
        velocity.y = -maxYVel;
    }
}

void TilePhysics::onCollision(Rect rect, Vec2d displ) {
}
