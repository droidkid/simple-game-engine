#pragma once

#include "engine/game.h"
#include "jump_game_scene.h"

class JumpGame : public Game {
public:
  int start() {
    Scene *scene = new JumpGameScene(getAssetLoader());
    return runScene(scene);
  }
};
