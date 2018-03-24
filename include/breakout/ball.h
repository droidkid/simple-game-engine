#pragma once

#include "game_object/physics_component.h"

class BallPhysics : public PhysicsComponent {
public:
    BallPhysics ( Rect rect, Vec2d velocity) : PhysicsComponent ( rect , velocity) {}
    void update(Input *input);
};

class BrickPhysics : public PhysicsComponent {
public:
    BrickPhysics ( int x, int y, int w, int h ) : PhysicsComponent ( x,y,w,h ) {}
    void update(Input *input) {};
};
