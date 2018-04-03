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

    Resources *resources;
    Camera *camera;

    GameObjectFactory *factory;
    GameObject *ball;

    int newBrickInterval = 3000;
    GameObject *minHeightBrick = NULL;

    void update ( Input *input ) override {
        // This logic should be managed in a different game object.
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
        handleCollisions ( gameObjects );
        camera->update ( gameObjects );

        // Call super class update.
        Scene::update();
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
