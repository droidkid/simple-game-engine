#pragma once

#include "input/input_poller.h"
#include "video/canvas.h"
#include "engine/scene.h"

class GameLoop {
    int current_tick_ms;
    int lag_ms;
    InputPoller *input_poller;
    Canvas *canvas;

public:
    GameLoop ( InputPoller *input_poller, Canvas *canvas );
    void runLoop ( Scene *scene );
};
