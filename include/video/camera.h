#pragma once

#include "game_object/physics_component.h"
#include "game_object/game_object.h"

// TODO(chesetti): Make this an interface.
class Camera {
    
    GameObject *subject; // The GameObject we want to keep in the box.
    int yLine;
    
public:
    void update(GameObject **gameObjects);
    void followYLine(GameObject *gameObject, int yLine);
};
