#include "jump_game_scene.h"

int randomInRange(int lowerBound, int upperBound) {
  int diff = upperBound - lowerBound + 1;
  return rand() % diff + lowerBound;
}

void JumpGameScene::update ( Input *input ) {
  // This logic should be managed in a different game object.
  newBrickInterval -= MS_PER_UPDATE;
  if ( newBrickInterval < 0 ) {
    if ( minHeightBrick == NULL ) {
      minHeightBrick = factory -> createTile ( randomInRange ( 0, SCREEN_WIDTH-30 ), SCREEN_HEIGHT - 200 );
      addGameObject ( minHeightBrick );
    } else {
      int curMinHeight = minHeightBrick->getPhysics()->y;
      if ( curMinHeight >  0 ) {
        minHeightBrick = factory -> createTile ( randomInRange ( 0, SCREEN_WIDTH - 30 ), curMinHeight - 200 );
        addGameObject ( minHeightBrick );
      }
    }
    newBrickInterval = 1000;
  }

  // Call super class update.
  Scene::update(input);
};

void JumpGameScene::onEvent(int eventType) {
  if (eventType == GameEvents::BALL_HIT_GROUND) {
    //Stub
  }
  if (eventType == GameEvents::BALL_HIT_TILE) {
    //Stub
  }
}


JumpGameScene::JumpGameScene ( AssetLoader *assetLoader ) {
  this->factory = new GameObjectFactory ( assetLoader );

  ball = factory->createJumpBall ( 400, 400, 0.7 );
  ball->getPhysics()->addObserver(this);

  addGameObject ( ball );
  addGameObject ( factory->createGround () );

  this->camera->followYLine(ball, SCREEN_HEIGHT * 0.50);
}
