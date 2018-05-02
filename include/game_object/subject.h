#pragma once

#include "game_object/observer.h"
#include "engine/game_engine_constants.h"

using namespace GameEngineConstants;

class Subject {
    Observer *observers[MAX_GAME_OBJECTS];
    protected:
        void notify(int eventType);
    public:
        Subject();
        void addObserver(Observer *observer);
        void removeObserver(Observer *observer);
};
