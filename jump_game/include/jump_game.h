#pragma once

#include "engine/game.h"
#include "jump_game_scene.h"
#include "game_constants.h"

using namespace GameConstants;

class JumpGame : public Game {
public:
  JumpGame() : Game(SCREEN_WIDTH, SCREEN_HEIGHT) {};
  int start() {
    Scene *scene = new JumpGameScene(getAssetLoader());
    return runScene(scene);
  }
};
