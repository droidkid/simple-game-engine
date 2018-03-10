#include "engine/scene.h"
#include "resources/resources.h"

class DummyScene : public Scene {

    Resources *resources;


    void update ( Input *input ) override {
    };

    void draw ( Canvas *canvas ) override {
        canvas->clearScreen();
        canvas->drawText ( "hello, world!", 200, 300, resources->font, {255,255,255} );
        canvas->renderScreen();
    };

public:
    DummyScene ( Resources *resources) {
        this->resources = resources;
    }
};
