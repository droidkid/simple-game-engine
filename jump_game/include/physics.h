#pragma once

#include "game_object/physics_component.h"
#include "game_object/game_object.h"
#include <math.h>

class JumpBallPhysics : public PhysicsComponent {
public:
    Vec2d accel;
    double maxYVel;
    JumpBallPhysics ( Rect rect, Vec2d velocity, Vec2d accel) :
      PhysicsComponent ( rect, velocity ), accel(accel), maxYVel(fabs(velocity.y)) {}
    void update(Input *input);
    void onCollision ( PhysicsComponent *otherPhysics, int objectType );
};

class TilePhysics : public PhysicsComponent {
public:
    bool isHitOnce;
    TilePhysics ( Rect rect ) : PhysicsComponent (rect, Vec2d(0,0)) {}
    void update(Input *input);
    void onCollision(PhysicsComponent *otherPhysics, int objectType) {}
};
