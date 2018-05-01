#pragma once

#include "sdl/sdl_system.h"
#include "sdl/asset_loader.h"
#include "input/input_poller.h"
#include "engine/game_loop.h"
#include "video/canvas.h"

class Game {
    SDLSystem *sdl_system;
    InputPoller *input_poller;
    GameLoop *game_loop;
    AssetLoader *assetLoader;
    Canvas *canvas;
public:
    Game();
    int run(int argc, char **argv);
};
