#pragma once

#include "game_object/game_object.h"
#include "sdl/asset_loader.h"
#include "sdl/sdl_system.h"

class GameObjectFactory {
    AssetLoader *assetLoader;
    SDL_Texture *blueBallTexture;
    SDL_Texture *redBrickTexture;
    SDL_Texture *backgroundTexture;

public:
    GameObjectFactory ( AssetLoader *assetLoader );
    GameObject* createJumpBall ( int x, int y, double maxYVel );
    GameObject* createTile ( int x, int y );
    GameObject* createTile ( int x, int y, int w, int h );
    GameObject* createGround ();
    SDL_Texture* getBackgroundTexture();
};
