#pragma once
#include "engine/scene.h"
#include "sdl/asset_loader.h"
#include "game_object/game_object.h"
#include "game_object/observer.h"
#include "game_object_types.h"
#include "game_object_factory.h"
#include "game_constants.h"

class JumpGameScene : public Observer, public Scene {
    AssetLoader *assetLoader;
    GameObjectFactory *factory;
    GameObject *ball;
    int newBrickInterval = 3000;
    GameObject *minHeightBrick = NULL;

  public:
    JumpGameScene(AssetLoader *assetLoader);
    void update (Input *input);
    void onEvent (int eventType);
};
