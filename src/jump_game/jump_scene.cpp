#include "engine/scene.h"
#include "resources/resources.h"
#include "game_object/game_object.h"
#include "jump_game/game_object_factory.h"
#include "jump_game/collisions.h"
#include "video/camera.h"
#include "game_constants.h"

using namespace GameConstants;

class JumpGameScene : public Scene {

    Resources *resources;
    Camera *camera;
    
    GameObject *ball;
    GameObjectFactory *factory;
    
    int newBrickInterval = 3000;

    int curIdx;
    GameObject **gameObjects;

    void update ( Input *input ) override {
        newBrickInterval -= MS_PER_UPDATE;
        if (newBrickInterval < 0) {
            addGameObject(factory->createTile(ball->getPhysics()->x - 30, ball->getPhysics()->y - 100));
            addGameObject(factory->createTile(ball->getPhysics()->x - 30, ball->getPhysics()->y + 100));
            newBrickInterval = 3000;
        }
        
        GameObject *curObject;
        for (int i=0; i<MAX_GAME_OBJECTS; i++) {
            curObject = gameObjects[i];
            if (curObject == NULL || curObject->canBeDestroyed()) {
                continue;
            }
            curObject->update(input);
        }
        
        handleCollisions(gameObjects);
        camera->update(gameObjects);
    };

    void addGameObject ( GameObject *object ) {
        int tries = MAX_GAME_OBJECTS;
        GameObject *curObject;
        
        while ( tries-- ) {
            curObject = gameObjects[curIdx];
            if ( curObject == NULL ) {
                gameObjects[curIdx++] = object;
                return;

            } else if ( curObject->canBeDestroyed() ) {
                // TODO(chesetti): Call curObject destructor
                gameObjects[curIdx++] = object;
                return;
            }
            curIdx++;
            if (curIdx >= MAX_GAME_OBJECTS) {
                curIdx = 0;
            }
        }
        
        // THROW ERROR HERE.
    }

    void draw ( Canvas *canvas ) override {
        canvas->clearScreen();
        GameObject *curObject;
        for (int i=0; i<MAX_GAME_OBJECTS; i++) {
            curObject = gameObjects[i];
            if (curObject == NULL || curObject->canBeDestroyed()) {
                continue;
            }
            curObject->draw(canvas);
        }
        canvas->renderScreen();
    };

public:
    JumpGameScene ( Resources *resources ) {
        this->resources = resources;
        this->camera = new Camera();
        this->factory = new GameObjectFactory ( resources );

        curIdx = 0;
        gameObjects = new GameObject*[MAX_GAME_OBJECTS];
        for (int i=0; i<MAX_GAME_OBJECTS; i++) {
            gameObjects[i] = NULL;
        }
        
        ball = factory->createJumpBall(400, 400, 0.7);

        addGameObject(ball);
        addGameObject(factory->createGround ());

        camera->follow( ball , Rect(SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.50, 0, 0));
    }
};
