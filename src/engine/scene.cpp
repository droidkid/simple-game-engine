#pragma once

#include "engine/scene.h"
#include "game_constants.h"

using namespace GameConstants;

Scene::Scene() {
    curIdx = 0;
    gameObjects = new GameObject*[MAX_GAME_OBJECTS];
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
}
