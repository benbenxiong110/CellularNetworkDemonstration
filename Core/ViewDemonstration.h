#pragma once
#include "ViewBase.h"
#include "DemoSidebar.h"
#include "DemoNotification.h"
#include "DemoMap.h"

namespace CellularNetworkDemonstration {
    class ViewDemonstration :public ViewBase {
    public:
        ViewDemonstration(SDL_Renderer* renderer, int viewCode);

        ~ViewDemonstration();

        virtual bool handleEvents(SDL_Event &event);

    private:
        // 属性

        // 资源


        // 子元素
        DemoSidebar *m_pSidebar;
        SDL_Rect *m_pSidebarRect;
        DemoNotification *m_pNotification;
        SDL_Rect *m_pNotificationRect;
        DemoMap *m_pMap;
        SDL_Rect *m_pMapRect;

        // 绘制界面元素
        virtual void doRender();

        virtual void doUpdate();
    };


}