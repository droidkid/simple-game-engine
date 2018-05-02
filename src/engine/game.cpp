#include "engine/game.h"

Game::Game() {
    sdlSystem = new SDLSystem();
    assetLoader = new AssetLoader(sdlSystem);
    inputPoller = new InputPoller();
    canvas = new Canvas(sdlSystem);
    gameLoop = new GameLoop(inputPoller, canvas);
}

AssetLoader* Game::getAssetLoader() {
  return assetLoader;
}

int Game::runScene(Scene *scene) {
  gameLoop->runLoop(scene);
  // TODO: make this return a value from gameLoop
  return 0;
}
