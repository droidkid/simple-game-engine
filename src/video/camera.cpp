#include "video/camera.h"
#include "game_constants.h"
#include "math/geometry.h"

using namespace GameConstants;

void Camera::update(GameObject **gameObjects) {
    if (isRectInside(subject->getPhysics()->getRect(), box)) {
        return;
    }
    
    Vec2d boxCenter = box.getCenter();
    Vec2d subCenter = subject->getPhysics()->getRect().getCenter();
    
    Vec2d diff = boxCenter.diff(subCenter);
    
    for (int i=0; i < MAX_GAME_OBJECTS; i++) {
        GameObject *curObject = gameObjects[i];
        if (curObject == NULL || curObject->canBeDestroyed() || curObject->shouldNotMoveWithCamera()) {
            continue;
        }
        curObject->getPhysics()->x += diff.x;
        curObject->getPhysics()->y += diff.y;
    }
}

void Camera::follow(GameObject *gameObject, Rect box) {
    this->subject = gameObject;
    this->box = box;
}

