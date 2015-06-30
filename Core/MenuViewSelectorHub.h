#pragma once
#include "Include.h"
#include "UIBase.h"
#include "MenuViewSelector.h"

namespace CellularNetworkDemonstration {
    class MenuViewSelectorHub : public UIBase {

    public:
        MenuViewSelectorHub(SDL_Renderer *renderer)
            :UIBase(renderer, 800, 450) {
            //初始化子元素

            // 设置属性
            m_iViewIndex = 0;
        }
        ~MenuViewSelectorHub() {
            // 清理子元素和资源
        }
        inline void setViewIndex(int index) {
            //TODO: Do page changing.
            m_iViewIndex = index;
        }

        inline int getViewIndex() const{
            return m_iViewIndex;
        }
    private:
        // 属性
        int m_iViewIndex;

        // 子元素


        // 绘制界面元素
        virtual void doRender() {
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 0);
            SDL_RenderClear(m_pRenderer);
        }
    };
}