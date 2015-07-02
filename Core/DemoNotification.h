#pragma once
#include "UIBase.h"

namespace CellularNetworkDemonstration {
    class DemoNotification : public UIBase {
    public:
        DemoNotification(SDL_Renderer *renderer)
            :UIBase(renderer, 200, 440) {

        }
        ~DemoNotification() {

        }
    };
}