#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "UIBase.h"
namespace CellularNetworkDemonstration {

    class MenuSystemClose :public UIBase {
    public:
        MenuSystemClose(SDL_Renderer *renderer)
            :UIBase(renderer, 45, 20) {
            //初始化子元素

        }
        ~MenuSystemClose() {
            // 清理子元素和资源
        }

    private:

        // 绘制界面元素
        virtual void renderUI() {
            SDL_SetRenderDrawColor(m_pRenderer, 220, 60, 60, 200);
            SDL_RenderClear(m_pRenderer);
        }
    };
}
