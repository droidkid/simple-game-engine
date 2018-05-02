#include <SDL.h>

#include "engine/game_engine_constants.h"
#include "engine/game_loop.h"

using namespace GameEngineConstants;

GameLoop::GameLoop ( InputPoller *input_poller, Canvas *canvas ) :
    input_poller ( input_poller ), canvas ( canvas ) {
    lag_ms = 0;
    current_tick_ms = 0;
}


void GameLoop::runLoop ( Scene *scene ) {
    bool quit_event_received = false;
    current_tick_ms = SDL_GetTicks();

    while ( !quit_event_received ) {
        Input *input = new Input();
        input_poller->pollInput(input);

        lag_ms += SDL_GetTicks() - current_tick_ms;
        current_tick_ms = SDL_GetTicks();

        while ( lag_ms >= MS_PER_UPDATE ) {
            scene->update(input);
            lag_ms -= MS_PER_UPDATE;
        }

        scene->drawScene ( canvas );
        quit_event_received = input->quit_event;
    }
}
