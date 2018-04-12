#pragma once

#include "video/camera.h"
#include "game_object/game_object.h"

class JumpCamera : public Camera {
    int yLine;
    GameObject* subject;

public:
    JumpCamera(GameObject *subject, int yLine): subject(subject), yLine(yLine) {};
    void update(GameObject **gameObjects);
};
