#include "breakout/game_object_factory.h"

GameObject* createBall ( int x, int y, Resources *resources ) {
    BallPhysics *physics = new BallPhysics ( Rect(x, y, 30, 30) , Vec2d(2, 3));
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( resources -> blueBallTexture );
    return new GameObject ( 0, physics, graphics );
}

GameObject * createBrick ( int x, int y, Resources* resources ) {
    BrickPhysics *physics = new BrickPhysics ( x, y, 60, 30 );
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( resources -> brickTextures[RED] );
    return new GameObject ( 1, physics, graphics );
}
