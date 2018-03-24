#pragma once

#include "game_object/physics_component.h"

class Camera {
    
    double translatePerFrame;
    int updatesTotranslate = 0;
    PhysicsComponent **physics;
    int numPhysics;
    
public:
    void update();
    void panUp(PhysicsComponent **physics, int numGameObjects, double distance, int time_ms); 
    
};
