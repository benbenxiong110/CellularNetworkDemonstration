#pragma once
#include "ViewBase.h"

namespace CellularNetworkDemonstration {
    class ViewIntroduce :public ViewBase {
    public:
        ViewIntroduce(SDL_Renderer* renderer, int viewCode);

        ~ViewIntroduce();

    private:
        // 属性

        // 资源
        SDL_Texture *m_pIntroduceImage;

        // 子元素

        // 绘制界面元素
        virtual void doRender();

        virtual void doUpdate();
    };


}