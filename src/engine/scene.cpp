#pragma once

#include "engine/game_engine_constants.h"
#include "engine/collisions.h"
#include "engine/scene.h"

using namespace GameEngineConstants;

Scene::Scene() {
    curIdx = 0;
    gameObjects = new GameObject*[MAX_GAME_OBJECTS];
    camera = new Camera();
    for ( int i=0; i<MAX_GAME_OBJECTS; i++ ) {
        gameObjects[i] = NULL;
    }
}

void Scene::update(Input *input) {
    GameObject *curObject;
    for ( int i=0; i<MAX_GAME_OBJECTS; i++ ) {
        curObject = gameObjects[i];
        if ( curObject == NULL || curObject->canBeDestroyed() ) {
            continue;
        }
        curObject->update ( input );
    }
    handleCollisions( gameObjects );
    camera->update( gameObjects );
}

void Scene::setCamera(Camera *camera) {
    // What about the old camera? Do we delete it?
    this->camera = camera;
}

void Scene::addGameObject(GameObject *object) {
    int tries = MAX_GAME_OBJECTS;
    GameObject *curObject;

    while ( tries-- ) {
        if ( curIdx >= MAX_GAME_OBJECTS ) {
            curIdx = 0;
        }
        curObject = gameObjects[curIdx];
        if ( curObject == NULL ) {
            gameObjects[curIdx++] = object;
            return;

        } else if ( curObject->canBeDestroyed() ) {
            delete curObject;
            gameObjects[curIdx++] = object;
            return;
        }
        curIdx++;
    }
    // THROW ERROR HERE.
}

void Scene::draw(Canvas *canvas) {
    GameObject *curObject;
    for ( int i=0; i<MAX_GAME_OBJECTS; i++ ) {
        curObject = gameObjects[i];
        if ( curObject == NULL || curObject->canBeDestroyed() ) {
            continue;
        }
        curObject->draw ( canvas );
    }
}

void Scene::drawScene(Canvas *canvas) {
    canvas->clearScreen();
    draw(canvas);
    canvas->renderScreen();
}
