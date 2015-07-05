#pragma once
#include "ViewBase.h"

namespace CellularNetworkDemonstration {
    class ViewAbout :public ViewBase {
    public:
        ViewAbout(SDL_Renderer* renderer, int viewCode);

        ~ViewAbout();

    private:
        // 属性

        // 资源
        SDL_Texture *m_pAboutImage;

        // 子元素

        // 绘制界面元素
        virtual void doRender();

        virtual void doUpdate();
    };


}