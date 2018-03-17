#include "game.h"

#include "scenes/breakout_scene.cpp"

Game::Game() {
    sdl_system = new SDLSystem();
    input_poller = new InputPoller();
    canvas = new Canvas(sdl_system);
    resources = new Resources(sdl_system);
    game_loop = new GameLoop(input_poller, canvas);
}

int Game::run ( int argc, char **argv ) {
    Scene *scene = new BreakoutScene(resources);
    game_loop->runLoop(scene);
    return 0;
}
