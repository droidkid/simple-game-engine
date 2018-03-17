#pragma once

#include "game_object/game_object.h"
#include "game_object/ball.h"
#include "game_object/graphics_component.h"
#include "resources/resources.h"

GameObject* createBall(int x, int y, Resources *resources); 
GameObject* createBrick(int x, int y, Resources *resources); 
