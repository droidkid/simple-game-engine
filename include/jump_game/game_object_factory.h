#pragma once

#include "game_object/game_object.h"
#include "resources/resources.h"

GameObject* createJumpBall ( int x, int y, double maxYVel, Resources *resources );
GameObject* createTile ( int x, int y, Resources *resources );
GameObject* createTile ( int x, int y, int w, int h, Resources *resources );
