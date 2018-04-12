#include "jump_game/jump_camera.h"
#include "game_constants.h"

using namespace GameConstants;

void JumpCamera::update(GameObject **gameObjects) {
    int subY = subject->getPhysics()->y;

    double diff = 0;
    if (subY < yLine) {
        diff = yLine - subY;
    }

    GameObject *gameObject;
    for (int i=0; i < MAX_GAME_OBJECTS; i++) {
        gameObject = gameObjects[i];
        if (gameObject == NULL || gameObject->canBeDestroyed() || gameObject->shouldNotMoveWithCamera()) {
            continue;
        }
        gameObject->getPhysics()->y += diff;
    }
}
