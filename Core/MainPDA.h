#pragma once
#include "MainMobileClient.h"
#include "DemoTextureManager.h"
namespace CellularNetworkDemonstration {
    class MainPDA : public MainMobileClient {
    public:
        MainPDA(int ID) :MainMobileClient(MAIN_MOBILE_CLIENT_PDA,ID) {

        }
        virtual SDL_Texture *render(SDL_Renderer *renderer) {
            return DemoTextureManager::get().getTexture(renderer, "icon-pda-small.png");
        }
    private:
    };
}