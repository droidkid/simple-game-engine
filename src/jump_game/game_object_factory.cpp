#include "jump_game/game_object_factory.h"
#include "jump_game/physics.h"

GameObject* createJumpBall ( int x, int y, double yvel, Resources *resources ) {
    JumpBallPhysics *physics = new JumpBallPhysics ( Rect(x, y, 30, 30) , Vec2d(0, yvel), Vec2d(0, 0.001));
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( resources -> blueBallTexture );
    return new GameObject ( physics, graphics );
}

GameObject* createTile ( int x, int y, Resources *resources ) {
    TilePhysics *physics = new TilePhysics (Rect(x, y, 100, 20));
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( resources -> brickTextures[RED] );
    return new GameObject ( physics, graphics );
}

GameObject* createTile( int x, int y, int w, int h, Resources *resources) {
    TilePhysics *physics = new TilePhysics (Rect(x, y, w, h));
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( resources -> brickTextures[RED] );
    return new GameObject ( physics, graphics );
}
