#pragma once

#include "video/canvas.h"
#include "input/input.h"
#include "game_object/game_object.h"

class Scene {
    int curIdx;
public:
    // TODO(chesetti): Create a Object Manager or something of the sort.
    // Exposing gameObjects as public doesn't seem safe.
    GameObject **gameObjects;
    Scene();
    virtual void update(Input *input); 
    virtual void draw(Canvas *canvas);
    void addGameObject(GameObject *object);
};
