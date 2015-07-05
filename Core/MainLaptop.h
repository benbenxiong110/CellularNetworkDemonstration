#pragma once
#include "MainMobileClient.h"
#include "DemoTextureManager.h"
namespace CellularNetworkDemonstration {
    class MainLaptop : public MainMobileClient {
    public:
        MainLaptop(int ID) :MainMobileClient(MAIN_MOBILE_CLIENT_LAPTOP, ID) {
            
        }
        virtual SDL_Texture *render(SDL_Renderer *renderer) {
            return DemoTextureManager::get().getTexture(renderer, "icon-laptop-small.png");
        }
    private:
    };
}