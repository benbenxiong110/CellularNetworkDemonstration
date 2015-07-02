#define DEBUG

#include <SDL.h>
#include "Application.h"
using namespace CellularNetworkDemonstration;

static Application* app = nullptr;

int main(int argc, char* args []) {
    // 初始化程序程序实例
    app = new Application();
    if (!app->init()) {
        SDL_log("程序初始化失败，请尝试重新运行。");
    }
        
    // 程序事件绘图循环
    while (app->running()) {
        app->handleEvents();
        app->update();
        app->render();
    }

    // 程序推出清理
    app->clean();
    return 0;
}
