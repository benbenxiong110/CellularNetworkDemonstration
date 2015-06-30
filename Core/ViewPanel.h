#pragma once
#include "Include.h"
#include "UIBase.h"
namespace CellularNetworkDemonstration {
    class ViewPanel :
        public UIBase {
    public:
        ViewPanel(SDL_Renderer *renderer)
            :UIBase(renderer, 800, 450) {
            //初始化子元素

            // 设置属性
            m_iViewIndex = 0;
        }
        ~ViewPanel() {
            // 清理子元素和资源
        }
        void setViewIndex(int index) {
            //TODO: Do page changing.
            m_iViewIndex = index;
        }
    private:
        // 属性
        int m_iViewIndex;

        // 子元素
        

        // 绘制界面元素
        virtual void doRender() {
            SDL_SetRenderDrawColor(m_pRenderer, getContiniousValue(4023), getContiniousValue(6732), getContiniousValue(9114), getContiniousValue(7333));
            SDL_RenderClear(m_pRenderer);
        }

        inline int getContiniousValue(int interval) {
            int tick = SDL_GetPerformanceCounter()  / interval % 512;
            if (tick > 255) {
                return 512 - tick;
            } else {
                return tick;
            }
        }
    };
}


