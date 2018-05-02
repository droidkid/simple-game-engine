#include "game_object_factory.h"
#include "physics.h"
#include "game_constants.h"

using namespace GameObjectTypes;
using namespace GameConstants;

GameObjectFactory::GameObjectFactory(AssetLoader *assetLoader) {
  assetLoader->loadPNGintoTexture("assets/puzzlepack/png/element_red_rectangle.png", &redBrickTexture);
  assetLoader->loadPNGintoTexture("assets/puzzlepack/png/ballBlue.png", &blueBallTexture);
}

GameObject* GameObjectFactory::createJumpBall ( int x, int y, double maxYVel) {
    JumpBallPhysics *physics = new JumpBallPhysics ( Rect(x, y, 30, 30) , Vec2d(0, maxYVel), Vec2d(0, 0.001));
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( blueBallTexture );
    return new GameObject ( BALL, physics, graphics );
}


GameObject* GameObjectFactory::createTile ( int x, int y) {
    TilePhysics *physics = new TilePhysics (Rect(x, y, 50, 20));
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( redBrickTexture );
    return new GameObject ( TILE, physics, graphics );
}

GameObject* GameObjectFactory::createTile( int x, int y, int w, int h) {
    TilePhysics *physics = new TilePhysics (Rect(x, y, w, h));
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( redBrickTexture );
    return new GameObject ( GROUND, physics, graphics );
}

GameObject* GameObjectFactory::createGround() {
    TilePhysics *physics = new TilePhysics (Rect(0, SCREEN_HEIGHT-10, SCREEN_WIDTH, 100));
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( redBrickTexture );
    GameObject *gameObject = new GameObject(GROUND, physics, graphics);
    gameObject->setShouldNotMoveWithCamera(true);
    return gameObject;
}
