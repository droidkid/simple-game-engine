#include "engine/scene.h"
#include "resources/resources.h"
#include "game_object/game_object.h"
#include "game_object/game_object_factory.h"

class BreakoutScene : public Scene {

    Resources *resources;
    GameObject *ball;
    GameObject *brick;

    void update ( Input *input ) override {
        ball->update();
        brick->update();
    };

    void draw ( Canvas *canvas ) override {
        canvas->clearScreen();
        ball->draw(canvas);
        brick->draw(canvas);
        canvas->renderScreen();
    };

public:
    BreakoutScene ( Resources *resources ) {
        this->resources = resources;
        ball = createBall(0, 0, resources);
        brick = createBrick(200,300,resources);
    }
};

