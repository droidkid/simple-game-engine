#include "game_object/game_object_factory.h"

GameObject* createBall ( int x, int y, Resources *resources ) {
    BallPhysics *physics = new BallPhysics ( x, y, 30, 30 );
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( resources -> blueBallTexture );
    return new GameObject ( physics, graphics );
}

GameObject * createBrick ( int x, int y, Resources* resources ) {
    BrickPhysics *physics = new BrickPhysics ( x, y, 60, 30 );
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( resources -> brickTextures[RED] );
    return new GameObject ( physics, graphics );
}
