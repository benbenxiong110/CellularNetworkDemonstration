#pragma once
#include "MainMobileClient.h"
#include "DemoTextureManager.h"
namespace CellularNetworkDemonstration {
    class MainMobilePhone : public MainMobileClient {
    public:
        MainMobilePhone(int ID, int x, int y) :MainMobileClient(MAIN_MOBILE_CLIENT_MOBILE_PHONE, ID, x, y) {
            this->velocity = 3;
            this->range = 3;
        }
        virtual SDL_Texture *render(SDL_Renderer *renderer) {
            return DemoTextureManager::get().getTexture(renderer, "icon-mobile-phone-small.png");
        }
    private:
    };
}