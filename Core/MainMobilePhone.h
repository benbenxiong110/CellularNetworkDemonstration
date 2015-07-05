#pragma once
#include "MainMobileClient.h"
#include "DemoTextureManager.h"
namespace CellularNetworkDemonstration {
    class MainMobilePhone : public MainMobileClient {
    public:
        MainMobilePhone(int ID) :MainMobileClient(MAIN_MOBILE_CLIENT_MOBILE_PHONE, ID) {

        }
        virtual SDL_Texture *render(SDL_Renderer *renderer) {
            return DemoTextureManager::get().getTexture(renderer, "icon-mobile-phone-small.png");
        }
    private:
    };
}