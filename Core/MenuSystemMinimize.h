#pragma once
#include "Include.h"
#include "UIBase.h"
namespace CellularNetworkDemonstration {

    class MenuSystemMinimize :public UIBase {
    public:
        MenuSystemMinimize(SDL_Renderer *renderer)
            :UIBase(renderer, 45, 20) {
            //初始化子元素

        }
        ~MenuSystemMinimize() {
            // 清理子元素和资源
        }

    private:

        // 绘制界面元素
        virtual void renderUI() {
            SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
            SDL_RenderClear(m_pRenderer);
        }
    };
}
