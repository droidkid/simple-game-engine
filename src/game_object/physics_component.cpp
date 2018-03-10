#include "game_object/physics_component.h"

PhysicsComponent::PhysicsComponent()
{
    this->x = 0;
    this->y = 0;
    this->w = 0;
    this->h = 0;
}

PhysicsComponent::~PhysicsComponent()
{
}


void PhysicsComponent::setRect(double x, double y, double w, double h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}


void PhysicsComponent::setX(double x)
{
    this->x = x;
}

void PhysicsComponent::setY(double y)
{
    this->y = y;
}

void PhysicsComponent::setXY(double x, double y)
{
    this->x = x;
    this->y = y;
}

void PhysicsComponent::setWidth(double w)
{
    this->w = w;
}

void PhysicsComponent::setHeight(double h)
{
    this->h = h;
}

void PhysicsComponent::setSize(double w, double h)
{
    this->w = w;
    this->h = h;
}

int PhysicsComponent::getX() {
	return x;
}

int PhysicsComponent::getY() {
	return y;
}

int PhysicsComponent::getWidth() {
	return w;
}

int PhysicsComponent::getHeight() {
	return h;
}






