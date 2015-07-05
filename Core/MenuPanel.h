#pragma once
#include "UIBase.h"

#include "MenuSystemClose.h"
#include "MenuSystemMinimize.h"
#include "MenuViewSelectorHub.h"
namespace CellularNetworkDemonstration {

    class MenuPanel 
        :public UIBase {
    public:
        MenuPanel(SDL_Renderer *renderer);

        ~MenuPanel();


        int getViewCode()const;
        void setViewCode(int indexCode);
    private:
        // 属性

        // 资源
        SDL_Texture *m_pMenuImage;

        // 子元素
        MenuSystemClose *m_pMenuSystemClose;
        SDL_Rect *m_pMenuSystemCloseRect;

        MenuSystemMinimize *m_pMenuSystemMinimize;
        SDL_Rect *m_pMenuSystemMinimizeRect;

        MenuViewSelectorHub *m_pMenuViewSelectorHub;
        SDL_Rect *m_pMenuViewSelectorHubRect;

        // 绘制界面元素
        virtual void doRender();

        virtual void doUpdate();
    };
}
