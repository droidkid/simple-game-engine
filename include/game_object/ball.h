#pragma once

#include "physics_component.h"
#include "graphics_component.h"

class BallPhysics : public PhysicsComponent {
public:
    BallPhysics ( int x, int y, int w, int h ) : PhysicsComponent ( x,y,w,h ) {}
    void update();
};

class BrickPhysics : public PhysicsComponent {
public:
    BrickPhysics ( int x, int y, int w, int h ) : PhysicsComponent ( x,y,w,h ) {}
    void update() {};
};
