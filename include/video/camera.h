#pragma once

#include "game_object/physics_component.h"
#include "game_object/game_object.h"

class Camera {
    int curMode;
    GameObject* subject;

    // For yLine follow.
    int yLine;

public:
    void update(GameObject **gameObjects); 

    // Helper methods that set how camera behaves.
    // Just adding the one needed now, will add other transforms later.
    void followYLine(GameObject *subject, int yLine);
};
