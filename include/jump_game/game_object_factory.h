#pragma once

#include "game_object/game_object.h"
#include "resources/resources.h"

class GameObjectFactory {
    Resources *resources;
public:
    GameObjectFactory ( Resources *resources ) : resources ( resources ) {};
    GameObject* createJumpBall ( int x, int y, double maxYVel );
    GameObject* createTile ( int x, int y );
    GameObject* createTile ( int x, int y, int w, int h );
    GameObject* createGround ();
};
