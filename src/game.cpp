#include "game.h"

#include "scenes/dummy_scene.cpp"

Game::Game() {
    sdl_system = new SDLSystem();
    input_poller = new InputPoller();
    canvas = new Canvas(sdl_system);
    game_loop = new GameLoop(input_poller, canvas);
}

int Game::run ( int argc, char **argv ) {
    Scene *scene = new DummyScene();
    game_loop->runLoop(scene);
    return 0;
}
