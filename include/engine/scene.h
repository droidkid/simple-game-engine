#pragma once

#include "video/canvas.h"
#include "video/camera.h"
#include "input/input.h"
#include "game_object/game_object.h"

class Scene {
    int curIdx;
public:
    GameObject **gameObjects;
    Camera *camera;
    Scene();
    virtual void update(Input *input);
    virtual void draw(Canvas *canvas);
    void drawScene(Canvas *canvas);
    void addGameObject(GameObject *object);
    void destroyAllGameObjects();
    void setCamera(Camera *camera);
};
