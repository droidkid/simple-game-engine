#include <SDL.h>

#include "input/input_poller.h"

void InputPoller::pollInput(Input *input)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            input->quit_event= true;
        }
    }
    SDL_GetMouseState(&(input->mouse_x), &(input->mouse_y));
}
