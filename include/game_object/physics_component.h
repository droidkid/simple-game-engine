#pragma once

class PhysicsComponent {
    double x, y;
    double w, h;
    
public:
    PhysicsComponent();
    void setX(double x);
    int getX();
    void setY(double y);
    int getY();
    void setXY(double x, double y);
    void setWidth(double w);
    int getWidth();
    void setHeight(double h);
    int getHeight();
    void setSize(double w, double h);
    void setRect(double x, double y, double w, double h);
    ~PhysicsComponent();
};
