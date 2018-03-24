#pragma once

#include "game_object/physics_component.h"
#include "game_object/graphics_component.h"

class GameObject {
    PhysicsComponent *physics;
    GraphicsComponent *graphics;

public:
    GameObject ( PhysicsComponent *physics, GraphicsComponent *graphics )
        : physics ( physics ), graphics ( graphics ) {}
    void update() {
        physics -> update();
    }
    
    void draw(Canvas *canvas) {
        graphics -> draw(canvas);
    }
    
    PhysicsComponent* getPhysics() {
        return physics;
    }
};
