#pragma once
#include "ViewBase.h"

namespace CellularNetworkDemonstration {
    class ViewWelcome:public ViewBase {
    public:
        ViewWelcome(SDL_Renderer* renderer,int viewCode);

        ~ViewWelcome();

    private:
        // 属性

        // 资源
        SDL_Texture *m_pWelcomeImage;

        // 子元素

        // 绘制界面元素
        virtual void doRender();

        virtual void doUpdate();
    };


}