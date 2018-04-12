#pragma once

#include "game_object/game_object.h"


// Probably could put all of this in a class and optimize it.
// Right now, just pass ALL objects into this. This function
// also has to take care of checking if objects are marked for destroyed.
void handleCollisions ( GameObject **gameObjects );
