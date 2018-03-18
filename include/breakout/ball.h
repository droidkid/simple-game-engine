#pragma once

#include "game_object/physics_component.h"
#include "game_object/graphics_component.h"

class BallPhysics : public PhysicsComponent {
public:
    Vec2d velocity;
    BallPhysics ( Rect rect, Vec2d velocity) : PhysicsComponent ( rect ), velocity( velocity) {}
    void update();
};

class BrickPhysics : public PhysicsComponent {
public:
    BrickPhysics ( int x, int y, int w, int h ) : PhysicsComponent ( x,y,w,h ) {}
    void update() {};
};
