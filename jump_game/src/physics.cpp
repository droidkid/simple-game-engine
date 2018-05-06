#include "physics.h"
#include "engine/game_engine_constants.h"
#include "game_constants.h"

using namespace GameConstants;
using namespace GameObjectTypes;

void JumpBallPhysics::update ( Input *input ) {

  double offset = 0.0;

  if ( input -> leftKeyDown ) {
    offset -= 5;
  }
  if ( input -> rightKeyDown ) {
    offset += 5;
  }

  x += ( velocity.x * MS_PER_UPDATE + 0.5 * ( accel.x ) + MS_PER_UPDATE*MS_PER_UPDATE/1e6 ) + offset;
  y += ( velocity.y * MS_PER_UPDATE + 0.5 * ( accel.y ) + MS_PER_UPDATE*MS_PER_UPDATE/1e6 );

  if (velocity.y > 0 && velocity.y > maxYVel) {
    velocity.y = maxYVel;
  }
  if (velocity.y < 0 && velocity.y  < -maxYVel) {
    velocity.y = -maxYVel;
  }

  velocity.x += accel.x * ( MS_PER_UPDATE );
  velocity.y += accel.y * MS_PER_UPDATE;

  if (x > SCREEN_WIDTH) {
    x = 0;
  }
  if (x < 0) {
    x = SCREEN_WIDTH - w;
  }
}

void JumpBallPhysics::onCollision ( PhysicsComponent *otherPhysics, int objectType ) {
  Rect ballRect = this->getRect();
  Rect otherRect = otherPhysics->getRect();

  if ( objectType == GROUND ) {
    if ( velocity.y > 0 ) {
      velocity.y = -maxYVel;
      notify(GameEvents::BALL_HIT_GROUND);
    }
  }

  if ( objectType == TILE) {
    double cy = ( ballRect.y + ballRect.h );
    double ry = ( otherRect.y + 0.25 * otherRect.h );
    TilePhysics *tilePhysics  = (TilePhysics *)otherPhysics;

    // Only reflect if colliding on way down.
    if ( velocity.y > 0 && cy > ry ) {
      velocity.y = -maxYVel;
      notify(GameEvents::BALL_HIT_TILE);
      if (!tilePhysics->isHitOnce) {
        notify(GameEvents::TILE_HIT_FIRST_TIME);
        tilePhysics->isHitOnce = true;
      }
    }

  }
}

void TilePhysics::update ( Input *input ) {
  Rect r = getRect();
  x += (velocity.x * MS_PER_UPDATE);
  if (x < 0) {
	x = 0;
	velocity.x = -velocity.x;
  }
  else if (x > SCREEN_WIDTH - TILE_WIDTH) {
	x = SCREEN_WIDTH - TILE_WIDTH;
	velocity.x = -velocity.x;
  }
  if ( r.x > SCREEN_WIDTH || r.y > SCREEN_HEIGHT ) {
    isDestroyed = true;
  }
}
