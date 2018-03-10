#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "game_object/physics_component.h"
#include "video/canvas.h"

class GraphicsComponent {
    SDL_Rect boundingBox;
	SDL_Texture *texture;
	PhysicsComponent *physicsComponent;

public:
	GraphicsComponent(PhysicsComponent *physics);
	void setTexture(SDL_Texture *texture);
	void draw(double interpolation, Canvas *canvas);
	~GraphicsComponent();
};
