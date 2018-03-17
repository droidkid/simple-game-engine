#pragma once

class PhysicsComponent {
    
public:
    double x, y;
    double w, h;
    PhysicsComponent() {};
    PhysicsComponent(double x, double y, double w, double h) : x(x), y(y), w(w), h(h) {};
    virtual void update() {};
    ~PhysicsComponent() {};
};
