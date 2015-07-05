#pragma once
#include "MainMobileClient.h"
#include "DemoTextureManager.h"
namespace CellularNetworkDemonstration {
    class MainPDA : public MainMobileClient {
    public:
        MainPDA(int ID, int x, int y) :MainMobileClient(MAIN_MOBILE_CLIENT_PDA,ID,x,y) {
            this->velocity = 2;
            this->range = 2;
        }
        virtual SDL_Texture *render(SDL_Renderer *renderer) {
            return DemoTextureManager::get().getTexture(renderer, "icon-pda-small.png");
        }
    private:
    };
}