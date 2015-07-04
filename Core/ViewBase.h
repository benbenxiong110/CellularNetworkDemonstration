#pragma once
#include "UIBase.h"
namespace CellularNetworkDemonstration {

    class ViewBase :
        public UIBase {
    public:
        ViewBase(SDL_Renderer *renderer, int viewCode)
            :UIBase(renderer, 800, 450), m_iViewCode(viewCode) {
        }
        virtual ~ViewBase() {
        }
        int getViewCode() const {
            return this->m_iViewCode;
        }
        virtual bool handleEvents(SDL_Event &event) {
            return false;
        }
    private:
        const int m_iViewCode;
    };

}

