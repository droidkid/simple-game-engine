#pragma once

#include "math/geometry.h"

class PhysicsComponent {
    
public:
    double x, y;
    double w, h;
    Vec2d velocity;
    PhysicsComponent() {};
    PhysicsComponent(double x, double y, double w, double h) : x(x), y(y), w(w), h(h) {};
    PhysicsComponent(Rect rect, Vec2d velocity) : x(rect.x), y(rect.y), w(rect.w), h(rect.h), velocity(velocity) {};
    virtual void update() {};
    virtual void onCollision(Rect collidingBody, Vec2d displacementVector) {};
    ~PhysicsComponent() {};
};
