#pragma once

#include "math/geometry.h"

class PhysicsComponent {
    
public:
    double x, y;
    double w, h;
    PhysicsComponent() {};
    PhysicsComponent(double x, double y, double w, double h) : x(x), y(y), w(w), h(h) {};
    PhysicsComponent(Rect rect) : x(rect.x), y(rect.y), w(rect.w), h(rect.h) {};
    virtual void update() {};
    ~PhysicsComponent() {};
};
