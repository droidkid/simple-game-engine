#include "engine/scene.h"

class DummyScene : public Scene {
    
    void update(Input *input) override {
    };
    
   void draw(Canvas *canvas) override {
       canvas->clearScreen();
       canvas->renderScreen();
   }; 
    
};
