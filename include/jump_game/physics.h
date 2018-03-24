#pragma once

#include "game_object/physics_component.h"
#include <math.h>

class JumpBallPhysics : public PhysicsComponent {
public:
    Vec2d accel;
    double maxYVel;
    JumpBallPhysics ( Rect rect, Vec2d velocity, Vec2d accel) : PhysicsComponent ( rect, velocity ), accel(accel), maxYVel(fabs(velocity.y)) {}
    void update();
    void onCollision(Rect collidingBody, Vec2d displacementVector);
};

class TilePhysics : public PhysicsComponent {
public:
    TilePhysics ( Rect rect ) : PhysicsComponent (rect, Vec2d(0,0)) {}
    void update() {};
    void onCollision(Rect collidingBody, Vec2d displacementVector);
};
