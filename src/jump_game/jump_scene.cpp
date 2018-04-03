#include "engine/scene.h"
#include "math/util.h"
#include "resources/resources.h"
#include "game_object/game_object.h"
#include "jump_game/game_object_factory.h"
#include "jump_game/collisions.h"
#include "video/camera.h"
#include "game_constants.h"

using namespace GameConstants;

class JumpGameScene : public Scene {

    // TODO(chesetti): Move common stuff to super class.

    Resources *resources;
    Camera *camera;

    GameObject *ball;
    GameObjectFactory *factory;

    int newBrickInterval = 3000;
    GameObject *minHeightBrick = NULL;

    int curIdx;
    GameObject **gameObjects;

    void update ( Input *input ) override {
        // This logic should be managed in a different class.
        newBrickInterval -= MS_PER_UPDATE;
        if ( newBrickInterval < 0 ) {
            if ( minHeightBrick == NULL ) {
                minHeightBrick = factory -> createTile ( random ( 0, SCREEN_WIDTH-30 ), SCREEN_HEIGHT - 200 );
                addGameObject ( minHeightBrick );
            } else {
                int curMinHeight = minHeightBrick->getPhysics()->y;
                if ( curMinHeight >  0 ) {
                    minHeightBrick = factory -> createTile ( random ( 0, SCREEN_WIDTH - 30 ), curMinHeight - 200 );
                    addGameObject ( minHeightBrick );
                }
            }
            newBrickInterval = 1000;
        }

        GameObject *curObject;
        for ( int i=0; i<MAX_GAME_OBJECTS; i++ ) {
            curObject = gameObjects[i];
            if ( curObject == NULL || curObject->canBeDestroyed() ) {
                continue;
            }
            curObject->update ( input );
        }

        handleCollisions ( gameObjects );
        camera->update ( gameObjects );
    };

    void addGameObject ( GameObject *object ) {
        int tries = MAX_GAME_OBJECTS;
        GameObject *curObject;

        while ( tries-- ) {
            if ( curIdx >= MAX_GAME_OBJECTS ) {
                curIdx = 0;
            }
            curObject = gameObjects[curIdx];
            if ( curObject == NULL ) {
                gameObjects[curIdx++] = object;
                cout<<curIdx<<endl;
                return;

            } else if ( curObject->canBeDestroyed() ) {
                // TODO(chesetti): Call curObject destructor
                gameObjects[curIdx++] = object;
                cout<<curIdx<<endl;
                return;
            }
            curIdx++;
        }
        cout<<"Exiting at" <<curIdx<<endl;

        // THROW ERROR HERE.
    }

    void draw ( Canvas *canvas ) override {
        canvas->clearScreen();
        GameObject *curObject;
        for ( int i=0; i<MAX_GAME_OBJECTS; i++ ) {
            curObject = gameObjects[i];
            if ( curObject == NULL || curObject->canBeDestroyed() ) {
                continue;
            }
            curObject->draw ( canvas );
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
        for ( int i=0; i<MAX_GAME_OBJECTS; i++ ) {
            gameObjects[i] = NULL;
        }

        ball = factory->createJumpBall ( 400, 400, 0.7 );

        addGameObject ( ball );
        addGameObject ( factory->createGround () );

        camera->followYLine ( ball , SCREEN_HEIGHT * 0.50 );
    }
};
