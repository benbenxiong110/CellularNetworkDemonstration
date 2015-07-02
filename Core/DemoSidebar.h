#pragma once
#include "UIBase.h"

namespace CellularNetworkDemonstration {
    class DemoSidebar : public UIBase {
    public:
        DemoSidebar(SDL_Renderer *renderer)
            :UIBase(renderer, 195, 440) {
        }

        ~DemoSidebar() {
                // 清理子元素和资源

                //DELETE_IF_EXIST(m_pMenuSystemMinimize)
                //    if (m_pMenuImage) {
                //        SDL_DestroyTexture(m_pMenuImage);
                //    }
            }


    private:
        // 属性

        // 资源
        //SDL_Texture *m_pMenuImage;

        // 子元素
        //MenuSystemClose *m_pMenuSystemClose;
        //SDL_Rect *m_pMenuSystemCloseRect;


        // 绘制界面元素
        virtual void doRender() {
            SDL_SetRenderDrawColor_DefalutBackground(m_pRenderer);
            SDL_SetRenderDrawColor(m_pRenderer, 200, 0, 0, 200);
            SDL_RenderClear(m_pRenderer);

        }

        virtual void doUpdate() {


        }
    };
}