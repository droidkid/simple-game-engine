#include "game_object_factory.h"
#include "physics.h"
#include "game_constants.h"

using namespace GameObjectTypes;
using namespace GameConstants;

GameObjectFactory::GameObjectFactory(AssetLoader *assetLoader) {
  this->assetLoader = assetLoader;
  assetLoader->loadPNGintoTexture("assets/brick.png", &brickTexture);
  assetLoader->loadPNGintoTexture("assets/ball.png", &ballTexture);
  assetLoader->loadPNGintoTexture("assets/sky.png", &backgroundTexture);
  assetLoader->loadTTFfont("assets/fonts/kenpixel.ttf", FONT_SIZE_PT, &font);
}

GameObject* GameObjectFactory::createJumpBall ( int x, int y) {
    JumpBallPhysics *physics = new JumpBallPhysics ( Rect(x, y, 2 * BALL_RADIUS, 2 * BALL_RADIUS),
                                                     Vec2d(0, MAX_BALL_VEL), Vec2d(0, MAX_BALL_ACCEL));
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( ballTexture );
    return new GameObject ( BALL, physics, graphics );
}


GameObject* GameObjectFactory::createTile ( int x, int y) {
    TilePhysics *physics = new TilePhysics (Rect(x, y, TILE_WIDTH, TILE_HEIGHT));
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( brickTexture );
    return new GameObject ( TILE, physics, graphics );
}

GameObject* GameObjectFactory::createTile( int x, int y, int w, int h) {
    TilePhysics *physics = new TilePhysics (Rect(x, y, w, h));
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    graphics->setTexture ( brickTexture );
    return new GameObject ( GROUND, physics, graphics );
}

GameObject* GameObjectFactory::createGround() {
    TilePhysics *physics = new TilePhysics (Rect(0, SCREEN_HEIGHT-10, SCREEN_WIDTH, 100));
    SimpleGraphicsComponent *graphics = new SimpleGraphicsComponent();
    graphics -> setPhysics ( physics );
    GameObject *gameObject = new GameObject(GROUND, physics, graphics);
    gameObject->setShouldNotMoveWithCamera(true);
    return gameObject;
}

TTF_Font* GameObjectFactory::getFont() {
  return font;
}

SDL_Texture* GameObjectFactory::getBackgroundTexture() {
  return backgroundTexture;
}
