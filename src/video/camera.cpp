#include "video/camera.h"
#include "engine/game_engine_constants.h"

using namespace GameEngineConstants;

void Camera::update(GameObject **gameObjects) {
    int subY = subject->getPhysics()->y;

    double diff = 0;
    if (subY < yLine) {
        diff = yLine - subY;
    }

    GameObject *gameObject;
    for (int i=0; i < MAX_GAME_OBJECTS; i++) {
        gameObject = gameObjects[i];
        if (gameObject == NULL || gameObject->isDestroyed() || gameObject->shouldNotMoveWithCamera()) {
            continue;
        }
        gameObject->getPhysics()->y += diff;
    }
}

void Camera::followYLine(GameObject *subject, int yLine) {
    this->yLine = yLine;
    this->subject = subject;
}
