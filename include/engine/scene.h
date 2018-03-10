#pragma once

#include "video/canvas.h"
#include "input/input.h"

class Scene {
public:
    virtual void update(Input *input) {}
    virtual void draw(Canvas *canvas) {}
};
