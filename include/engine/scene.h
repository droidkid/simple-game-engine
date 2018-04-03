#pragma once

#include "video/canvas.h"
#include "input/input.h"
#include "game_object/game_object.h"

class Scene {
    int curIdx;
    GameObject **gameObjects;
public:
    void update(Input *input); 
    void addGameObject(GameObject *object);
    void draw(Canvas *canvas);
};
