#include "jump_game_scene.h"
#include "game_constants.h"

#include <stdio.h>
#include <stdlib.h>

using namespace GameConstants;
using namespace GameState;

int randomInRange(int lowerBound, int upperBound) {
  int diff = upperBound - lowerBound + 1;
  return rand() % diff + lowerBound;
}

void JumpGameScene::update ( Input *input ) {
  if (curGameState == PRE_START) {
    if (input->enterPressed) {
      ball = factory->createJumpBall ( SCREEN_WIDTH/2, SCREEN_HEIGHT - 80);
      ball->getPhysics()->addObserver(this);
      minHeightBrick = factory -> createTile(SCREEN_WIDTH/2, SCREEN_HEIGHT - 40 , 0);

      addGameObject( minHeightBrick );
      addGameObject ( ball );
      addGameObject ( factory->createGround () );
      this->camera->followYLine(ball, SCREEN_HEIGHT * 0.25);

      tilesJumped = 0;
      newBrickInterval = 0;

      curGameState = IN_GAME;
    }
  }

  else if (curGameState == IN_GAME) {
    newBrickInterval -= MS_PER_UPDATE;
    if ( newBrickInterval < 0 ) {
      int curMinHeight = minHeightBrick->getPhysics()->y;
      if ( curMinHeight >  0 ) {
        minHeightBrick = factory -> createTile ( randomInRange ( 0, SCREEN_WIDTH - 30 ), 
									curMinHeight - 200  , randomInRange(0, 3) / 10.0);
        addGameObject ( minHeightBrick );
        minHeightBrick -> getPhysics()->addObserver(this);
      }
      newBrickInterval = DURATION_BETWEEN_BRICKS;
    }
    // Call super class update.
    Scene::update(input);
  }

  else if (curGameState == GAME_OVER) {
    gameOverInterval -= MS_PER_UPDATE;
    if (gameOverInterval < 0) {
      destroyAllGameObjects();
      gameOverInterval = DURATION_GAME_OVER_SCREEN;
      curGameState = PRE_START;
    }
  }

};

void JumpGameScene::onEvent(int eventType) {
  if (eventType == GameEvents::BALL_HIT_GROUND) {
    curGameState = GAME_OVER;
    gameOverInterval = DURATION_GAME_OVER_SCREEN;
  }
  if (eventType == GameEvents::TILE_HIT_FIRST_TIME) {
    tilesJumped++;
  }
}

void JumpGameScene::draw(Canvas *canvas) {
  canvas->drawTexture(factory->getBackgroundTexture(), {0,0,SCREEN_WIDTH, SCREEN_HEIGHT});
  if (curGameState == PRE_START) {
    canvas->drawText("JUMP GAME!", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, factory->getFont(), {0, 0, 0});
    canvas->drawText("PRESSS ENTER TO START.", SCREEN_WIDTH/2-100, SCREEN_HEIGHT/2 + 20, factory->getFont(), {0, 0, 0});
    canvas->drawText("ARROW KEYS TO CONTROL.", SCREEN_WIDTH/2-100, SCREEN_HEIGHT/2 + 40, factory->getFont(), {0, 0, 0});
  }
  if (curGameState == IN_GAME) {
    sprintf(scoreText, "SCORE: %d", tilesJumped);
    canvas->drawText(scoreText, SCREEN_WIDTH - 150, 40, factory->getFont(), {0, 0, 0});
    Scene::draw(canvas);
  }
  if (curGameState == GAME_OVER) {
    sprintf(scoreText, "SCORE: %d", tilesJumped);
	canvas->drawText(scoreText, SCREEN_WIDTH - 150, 40, factory->getFont(), {0, 0, 0});
    canvas->drawText("GAME OVER!", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, factory->getFont(), {0, 0, 0});
  }
}


JumpGameScene::JumpGameScene ( AssetLoader *assetLoader ) {
  this->factory = new GameObjectFactory ( assetLoader );
  curGameState = PRE_START;
}
