#include "video/camera.h"
#include "game_constants.h"

using namespace GameConstants;

void Camera::update() {
    if (updatesTotranslate > 0) {
        for (int i=0; i<numPhysics; i++) {
            physics[i]->y += translatePerFrame;
        }
        updatesTotranslate--;
    }
}

void Camera::panUp(PhysicsComponent **physics, int numGameObjects, double distance, int time_ms)
{
    this->physics = physics;
    this->numPhysics = numGameObjects;
    updatesTotranslate = time_ms / MS_PER_UPDATE;
    translatePerFrame = distance / updatesTotranslate;
}

