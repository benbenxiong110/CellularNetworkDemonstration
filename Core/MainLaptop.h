#pragma once
#include "MainMobileClient.h"
#include "DemoTextureManager.h"
namespace CellularNetworkDemonstration {
    class MainLaptop : public MainMobileClient {
    public:
        MainLaptop(int ID, int x, int y) :MainMobileClient(MAIN_MOBILE_CLIENT_LAPTOP, ID, x, y) {
            this->velocity = 1;
            this->range = 1;

        }
        virtual SDL_Texture *render(SDL_Renderer *renderer) {
            return DemoTextureManager::get().getTexture(renderer, "icon-laptop-small.png");
        }
    private:
    };
}