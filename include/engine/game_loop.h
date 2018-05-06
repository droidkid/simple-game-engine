#pragma once

#include "input/input_poller.h"
#include "video/canvas.h"
#include "engine/scene.h"

class GameLoop {
    int currentTickMs;
    int lagMs;
    InputPoller *inputPoller;
    Canvas *canvas;

public:
    GameLoop ( InputPoller *inputPoller, Canvas *canvas );
    void runLoop ( Scene *scene );
};
