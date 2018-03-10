#pragma once

class PhysicsComponent {
    double x, y;
    double w, h;
    
public:
    PhysicsComponent();
    void setX(double x);
    void setY(double y);
    void setXY(double x, double y);
    void setWidth(double w);
    void setHeight(double h);
    void setSize(double w, double h);
    void setRect(double x, double y, double w, double h);
    ~PhysicsComponent();
};
