#include "game_object/graphics_component.h"

// Holds texture and does drawing of sprite.

GraphicsComponent::GraphicsComponent(PhysicsComponent *physics) {
	this->physicsComponent = physics;
}

void GraphicsComponent::setTexture(SDL_Texture *texture) {
	this->texture = texture;
}

void GraphicsComponent::draw(double interpolation, Canvas *canvas) {
	double x = physicsComponent->getX();
	double y = physicsComponent->getY();
	double w = physicsComponent->getWidth();
	double h = physicsComponent->getHeight();

	boundingBox.x = (int)(x);
	boundingBox.y = (int)(y);
	boundingBox.w = (int)(w);
	boundingBox.h = (int)(h);

	canvas->drawTexture(texture, &boundingBox);
}

GraphicsComponent::~GraphicsComponent() {

}
