#pragma once

#include "jump_game//physics.h"
#include "math/geometry.h"
#include "video/camera.h"

#include <iostream>
using namespace std;

bool handleBallTileCollision(PhysicsComponent *ball, PhysicsComponent *tile) {
    
    Rect ballRect = Rect(ball->x, ball->y, ball->w, ball->h);
    Rect tileRect = Rect(tile->x, tile->y, tile->w, tile->h);
    
    double ball_cy = (ballRect.y + ballRect.h);
    double ball_ry = (tileRect.y + 5);
    
    if (isRectIntersect(ballRect, tileRect) && ball_cy < ball_ry) {
        ball->onCollision(tileRect, Vec2d(0,0));
        tile->onCollision(ballRect, Vec2d(0,0));
        return true;
    }
    return false;
    
}
