#pragma once

#include "game_object/physics_component.h"
#include "game_object/graphics_component.h"

class GameObject {
    PhysicsComponent *physics;
    GraphicsComponent *graphics;

public:
    GameObject ( PhysicsComponent *physics, GraphicsComponent *graphics )
        : physics ( physics ), graphics ( graphics ) {}
};
