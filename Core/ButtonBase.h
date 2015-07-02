#pragma once
#include "Include.h"
#include "UIBase.h"

namespace CellularNetworkDemonstration {
    class ButtonBase :public UIBase {
    public:
        // 
        ButtonBase(SDL_Renderer *renderer, int width, int height) :
            UIBase(renderer, width, height) {
            //初始化子元素
            m_pState = BUTTON_STATE_NORMAL;

        }
        virtual ~ButtonBase() {
        }

    protected:
        enum buttonState {
            BUTTON_STATE_NORMAL,
            BUTTON_STATE_HOVER,
            BUTTON_STATE_DOWN
        };
        buttonState m_pState;
        virtual void doAction() = 0;
    private:
        virtual void doUpdate() {
            // Null for default
            if (m_sMousePosition.x >= 0) {
                if (MouseManager::get().isLeftButtonDown()) {
                    m_pState = BUTTON_STATE_DOWN;
                } else {
                    if (m_pState == BUTTON_STATE_DOWN) {
                        doAction();
                    }
                    m_pState = BUTTON_STATE_HOVER;
                }
            } else {
                m_pState = BUTTON_STATE_NORMAL;
            }
        }
    };

}


