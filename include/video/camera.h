#pragma once

#include "game_object/physics_component.h"
#include "game_object/game_object.h"

class Camera {
public:
    virtual void update(GameObject **gameObjects) {} 
};
