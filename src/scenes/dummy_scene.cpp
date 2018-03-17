#include "engine/scene.h"
#include "resources/resources.h"
#include "game_object/game_object.h"

class DummyScene : public Scene {

    Resources *resources;
    int x, y;


    void update ( Input *input ) override {
        x = input -> mouse_x;
        y = input -> mouse_y;
    };

    void draw ( Canvas *canvas ) override {
        canvas->clearScreen();

        PhysicsComponent *physicsComponent = new PhysicsComponent(x, y, 30, 30);
        GraphicsComponent *graphicsComponent = new GraphicsComponent ( physicsComponent , resources -> blueBallTexture);
        graphicsComponent->draw ( 0.0, canvas );

        char text[30];
        sprintf(text, "Mouse_X: %d Mouse_Y: %d", x, y);

        canvas->drawText ( text, 200, 300, resources->font, {255,255,255} );
        canvas->renderScreen();
    };

public:
    DummyScene ( Resources *resources ) {
        this->resources = resources;
    }
};
