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
    GameObject *ground;
    GameObject **tiles;
    int numTiles;
    
    PhysicsComponent **physics;
    
    void update ( Input *input ) override {
        ball->update();
        for (int i=0; i<numTiles; i++) {
            tiles[i]->update();
            if(handleBallTileCollision(ball->getPhysics(), tiles[i]->getPhysics())) {
                cout<<i<<endl;
            }; 
                double dist = 300 - ball->getPhysics()->y;
                camera->panUp(physics, numTiles+1, dist, 10 * MS_PER_UPDATE);
        }
        camera->update();
        handleBallTileCollision(ball->getPhysics(), ground->getPhysics()); 
    };

    void draw ( Canvas *canvas ) override {
        canvas->clearScreen();
        ball->draw(canvas);
        for (int i=0; i<numTiles; i++) {
            tiles[i]->draw(canvas);
        }
        canvas->renderScreen();
    };

public:
    JumpGameScene ( Resources *resources ) {
        this->resources = resources;
        this->camera = new Camera();
        
        numTiles = 100;
        tiles = new GameObject*[numTiles];
        for (int i=0; i<numTiles; i++) {
            tiles[i] = createTile(400, -i*100 + 800, resources);
        }
        
        ball = createJumpBall(400, 400, 0.5, resources);
        ground = createTile(0, SCREEN_HEIGHT-10, SCREEN_WIDTH, 30, resources);
        
        physics = new PhysicsComponent*[numTiles+1];
        physics[0] = ball->getPhysics();
        for (int i=0; i<numTiles; i++) {
            physics[i+1] = tiles[i]->getPhysics();
        }
        
        //camera->panUp(physics, 2, 100, 1000);
    }
};
