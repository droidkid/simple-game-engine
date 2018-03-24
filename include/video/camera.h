#pragma once

#include "game_object/physics_component.h"
#include "game_object/game_object.h"

// TODO(chesetti): Make this an interface.
class Camera {
    
    GameObject *subject; // The GameObject we want to keep in the box.
    Rect box; // The box we want our gameObject always want to be in.
    
public:
    void update(GameObject **gameObjects);
    void follow(GameObject *gameObject, Rect box);
};
