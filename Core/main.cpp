#define DEBUG

#include<SDL.h>
#include "Application.h"
using namespace CellularNetworkDemonstration;

static Application* app = nullptr;

int main(int argc, char* args []) {

    app = new Application();
    app->init();

    while (app->running()) {
        app->handleEvents();
        app->update();
        app->render();
    }

    app->clean();
    return 0;
    return 0;
}