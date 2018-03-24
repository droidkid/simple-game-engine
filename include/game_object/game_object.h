#pragma once

#include "game_object/physics_component.h"
#include "game_object/graphics_component.h"

class GameObject {
    int objectType;
    int notMoveWithCamera;
    PhysicsComponent *physics;
    GraphicsComponent *graphics;

public:
    GameObject ( int objectType, PhysicsComponent *physics, GraphicsComponent *graphics )
        : objectType(objectType), physics ( physics ), graphics ( graphics ), notMoveWithCamera(0) {}
    void update(Input *input) {
        physics -> update(input);
    }
    
    void draw(Canvas *canvas) {
        graphics -> draw(canvas);
    }
    
    PhysicsComponent* getPhysics() {
        return physics;
    }
    
    int canBeDestroyed() {
        return physics->canBeDestroyed;
    }
    
    int getObjectType() {
        return objectType;
    }
    
    int shouldNotMoveWithCamera() {
        return notMoveWithCamera;
    }
    
    void setShouldNotMoveWithCamera(int val) {
        notMoveWithCamera = val;
    }
};
