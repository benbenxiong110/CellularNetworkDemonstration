#pragma once
#include "UIBase.h"
#include "DemoDataManager.h"
#include "DemoBaseStationListItem.h"
#include "DemoMobileClientListItem.h"
#include "DemoAttributeListItem.h"

namespace CellularNetworkDemonstration {
    class DemoSidebar : public UIBase {
    public:
        DemoSidebar(SDL_Renderer *renderer);

        ~DemoSidebar();

        void deepLevel();
        void upLevel();

        void setLevel(int level);

        virtual bool handleEvents(SDL_Event &event);

    private:
        // 属性
        bool m_bSwitching = false;
        int m_iSelectedTypeLv1 = 0; // 0 - 基站， 1 - 移动台
        int m_iSelectedIdLv1 = 0;
        int m_iSelectedTypeLv2 = 1; // 1 - Chipset, 2 - Screen, 3 - Keyboard
        int m_iCurrentLevel = 0;
        int m_iPreviousLevel = 0;


        // 资源
        SDL_Texture *m_pTitleText;
        SDL_Rect *m_pTitleTextRect;
        SDL_Texture *m_pBaseStationListTitle;
        SDL_Rect *m_pBaseStationListTitleRect;
        SDL_Texture *m_pMobileClientListTitle;
        SDL_Rect *m_pMobileClientListTitleRect;
        SDL_Texture *m_pArrow;
        SDL_Rect *m_pArrowLv1Rect;
        SDL_Rect *m_pArrowLv2Rect;
        SDL_Texture *m_pBaseStationTitle;
        SDL_Rect *m_pBaseStationTitleRect;
        SDL_Texture *m_pMoblieClientTitle;
        SDL_Rect *m_pMoblieClientTitleRect;
        SDL_Texture *m_pKeyboardTitle;
        SDL_Rect *m_pKeyboardTitleRect;
        SDL_Texture *m_pScreenTitle;
        SDL_Rect *m_pScreenTitleRect;
        SDL_Texture *m_pChipsetTitle;
        SDL_Rect *m_pChipsetTitleRect;

        vector<DemoBaseStationListItem *> m_vpBaseStationList;
        vector<DemoMoblieClientListItem *> m_vpMobileClientList;
        vector<DemoAttributeListItem *>m_vpAttributeListLv1;
        vector<DemoAttributeListItem *>m_vpAttributeListLv2;
        // 子元素
        //MenuSystemClose *m_pMenuSystemClose;
        //SDL_Rect *m_pMenuSystemCloseRect;

        bool updateListItemLv1(int lv1Type, int lv1Id);
        bool updateListItemLv2(int lv1Type, int lv1Id, int lv2Type);

        // 绘制界面元素
        virtual void doRender();
        void renderLevel(int l);

        int getAnimationValue();

        double easeInOut(double val);

        virtual void doUpdate();
    };
}