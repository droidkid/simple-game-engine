#pragma once

#include "math/geometry.h"
#include "input/input.h"
#include "game_object/subject.h"

class PhysicsComponent : public Subject {

public:
    double x, y;
    double w, h;
    Vec2d velocity;
    // Putting isDestroyed here since this is useful here.
    // At this point, PhysicsComponent should probably be GameLogicComponent.
    bool isDestroyed = false;
    PhysicsComponent() {};
    PhysicsComponent(double x, double y, double w, double h) : x(x), y(y), w(w), h(h) {};
    PhysicsComponent(Rect rect, Vec2d velocity) : x(rect.x), y(rect.y), w(rect.w), h(rect.h), velocity(velocity) {};
    virtual void update(Input *input) {};
    virtual void onCollision(Rect collidingBody, Vec2d displacementVector, int objectType) {};
    Rect getRect() { return Rect(x, y, w, h); };
    ~PhysicsComponent() {};
};
