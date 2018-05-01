#include "engine/scene.h"
#include "sdl/asset_loader.h"
#include "game_object/game_object.h"
#include "game_object/observer.h"
#include "game_object_types.h"
#include "game_object_factory.h"
#include "game_constants.h"

#include <iostream>

using namespace GameConstants;
using namespace std;

class JumpGameScene : public Scene, public Observer {

    AssetLoader *assetLoader;

    GameObjectFactory *factory;
    GameObject *ball;

    int newBrickInterval = 3000;
    GameObject *minHeightBrick = NULL;

    int randomInRange(int lowerBound, int upperBound) {
      int diff = upperBound - lowerBound + 1;
      return rand() % diff + lowerBound;
    }

    void update ( Input *input ) {
        // This logic should be managed in a different game object.
        newBrickInterval -= MS_PER_UPDATE;
        if ( newBrickInterval < 0 ) {
            if ( minHeightBrick == NULL ) {
                minHeightBrick = factory -> createTile ( randomInRange ( 0, SCREEN_WIDTH-30 ), SCREEN_HEIGHT - 200 );
                addGameObject ( minHeightBrick );
            } else {
                int curMinHeight = minHeightBrick->getPhysics()->y;
                if ( curMinHeight >  0 ) {
                    minHeightBrick = factory -> createTile ( randomInRange ( 0, SCREEN_WIDTH - 30 ), curMinHeight - 200 );
                    addGameObject ( minHeightBrick );
                }
            }
            newBrickInterval = 1000;
        }

        // Call super class update.
        Scene::update(input);
    };

    void onEvent(int eventType) {
        if (eventType == GameEvents::BALL_HIT_GROUND) {
            cout<<"BALL FELL ON GROUND"<<endl;
        }
        if (eventType == GameEvents::BALL_HIT_TILE) {
            cout<<"BALL HIT A TILE"<<endl;
        }
    }


public:
    JumpGameScene ( AssetLoader *assetLoader ) {
        this->factory = new GameObjectFactory ( assetLoader );

        ball = factory->createJumpBall ( 400, 400, 0.7 );
        ball->getPhysics()->addObserver(this);

        addGameObject ( ball );
        addGameObject ( factory->createGround () );

        this->camera->followYLine(ball, SCREEN_HEIGHT * 0.50);
    }
};
