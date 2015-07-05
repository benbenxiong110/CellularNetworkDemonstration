#pragma once
#include "ViewBase.h"
#include "DemoSidebar.h"
#include "DemoNotification.h"
#include "DemoMap.h"

namespace CellularNetworkDemonstration {
    class ViewDemonstration :public ViewBase {
    public:
        ViewDemonstration(SDL_Renderer* renderer, int viewCode)
            :ViewBase(renderer, viewCode) {
            //m_pDemonstrationImage = IMG_LoadTexture(m_pRenderer, "view-demonstration.png");

            m_pSidebar = new DemoSidebar(m_pRenderer);
            m_pSidebarRect = new SDL_Rect{ 0, 5, 195, 440 };
            m_pMap = new DemoMap(m_pRenderer);
            m_pMapRect = new SDL_Rect{ 195, 5, 600, 440 };

        }

        ~ViewDemonstration() {
            DELETE_IF_EXIST(m_pSidebar)
                DELETE_IF_EXIST(m_pSidebarRect)
                DELETE_IF_EXIST(m_pMap)
                DELETE_IF_EXIST(m_pMapRect)
                DELETE_IF_EXIST(m_pNotification)
                DELETE_IF_EXIST(m_pNotificationRect)
        }

        virtual bool handleEvents(SDL_Event &event) {

            return m_pMap->handleEvents(event) || m_pSidebar->handleEvents(event);// || m_pNotification->handleEvents(event);
        }

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
        virtual void doRender() {
            //m_pMenuSystemCloseRect->x = m_sMousePosition.x - m_pMenuSystemCloseRect->w/2;
            //m_pMenuSystemCloseRect->y = m_sMousePosition.y - m_pMenuSystemCloseRect->h / 2;

            SDL_SetRenderDrawColor_DefalutBackground(m_pRenderer);
            SDL_RenderClear(m_pRenderer);

            SDL_Texture *sidebarTexture = m_pSidebar->render();
            SDL_Texture *mapTexture = m_pMap->render();
            //SDL_Texture *notificationTexture = m_pNotification->render();

            SDL_RenderCopy(m_pRenderer, sidebarTexture, m_pSidebar->Rect(), m_pSidebarRect);
            SDL_RenderCopy(m_pRenderer, mapTexture, m_pMap->Rect(), m_pMapRect);
            //SDL_RenderCopy(m_pRenderer, notificationTexture, m_pNotification->Rect(), m_pNotificationRect);

        }

        virtual void doUpdate() {
            // Update data
            DemoDataManager::get().updateValue();

            if (SDL_PointInRect(m_sMousePosition, *m_pSidebarRect)) {
                m_pSidebar->update(SDL_RelationPoint(&m_sMousePosition, m_pSidebarRect));
            } else {
                m_pSidebar->update();
            }
            if (SDL_PointInRect(m_sMousePosition, *m_pMapRect)) {
                m_pMap->update(SDL_RelationPoint(&m_sMousePosition, m_pMapRect));
            } else {
                m_pMap->update();
            }

        }
    };


}