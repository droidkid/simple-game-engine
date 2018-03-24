#include <SDL.h>

#include "input/input_poller.h"

void InputPoller::pollInput(Input *input)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            input->quit_event= true;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT) {
            input->left_key_down = true;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT) {
            input->right_key_down = true;
        }
    }
    SDL_GetMouseState(&(input->mouse_x), &(input->mouse_y));
}
