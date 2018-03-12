#include "engine/scene.h"
#include "resources/resources.h"
#include "game_object/game_object.h"

class DummyScene : public Scene {

    Resources *resources;


    void update ( Input *input ) override {
    };

    void draw ( Canvas *canvas ) override {
        canvas->clearScreen();
        
        PhysicsComponent *physicsComponent = new PhysicsComponent();
        physicsComponent->setX(200);
        physicsComponent->setY(200);
        physicsComponent->setWidth(30);
        physicsComponent->setHeight(30);
        GraphicsComponent *graphicsComponent = new GraphicsComponent(physicsComponent);
        graphicsComponent -> setTexture(resources->blueBallTexture);
        graphicsComponent->draw(0.0, canvas);
        
        
        canvas->drawText ( "hello, world!", 200, 300, resources->font, {255,255,255} );
        canvas->renderScreen();
    };

public:
    DummyScene ( Resources *resources) {
        this->resources = resources;
    }
};
