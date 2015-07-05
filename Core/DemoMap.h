#pragma once
#include "UIBase.h"
#include "DemoHexagon.h"
#include "DemoMapIcon.h"

namespace CellularNetworkDemonstration {
    class DemoMap : public UIBase {
    public:
        DemoMap(SDL_Renderer *renderer)
            :UIBase(renderer, 600, 440) {

            // 加载资源

            //初始化子元素
            //m_pMenuSystemClose = new MenuSystemClose(m_pRenderer);
            //m_pMenuSystemCloseRect = new SDL_Rect();
            //m_pMenuSystemCloseRect->x = getWidth() - 50;
            //m_pMenuSystemCloseRect->y = 0;
            //m_pMenuSystemCloseRect->w = 45;
            //m_pMenuSystemCloseRect->h = 20;
            
            //hexagon = new DemoHexagon(renderer);

            vector<MainBaseStation *>& baseStationList
                = DemoDataManager::get().getBaseStationList();
            for (unsigned int i = 0; i < baseStationList.size(); i++) {
                m_vpHexagon.push_back(new DemoHexagon(m_pRenderer, baseStationList[i]->getId()));
            }

            vector<MainMobileClient *>& mobileClientList
                = DemoDataManager::get().getMobileClientList();
            for (unsigned int i = 0; i < mobileClientList.size(); i++) {
                m_vpMapIcon.push_back(new DemoMapIcon(m_pRenderer, mobileClientList[i]->getId()));
            }

        }

        ~DemoMap() {
            // 清理子元素和资源
            //DELETE_IF_EXIST(hexagon);

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
        
        vector<DemoHexagon *>m_vpHexagon;
        vector<DemoMapIcon *>m_vpMapIcon;

        // 绘制界面元素
        virtual void doRender() {
            SDL_SetRenderDrawColor(m_pRenderer, 20, 220, 120, 255);
            SDL_RenderClear(m_pRenderer);
            
            
            SDL_Rect r;
            r = { 0, 0, 400, 400 };
            for (unsigned int i = 0; i < m_vpHexagon.size(); i++) {
                DemoHexagon *hexagon = m_vpHexagon[i];
                r.x = DemoDataManager::get().getBaseStation(hexagon->getBaseStationId())->getX() - 200;
                r.y = DemoDataManager::get().getBaseStation(hexagon->getBaseStationId())->getY() - 200;
                SDL_RenderCopy(m_pRenderer, hexagon->render(), hexagon->Rect(), &r);
            }

            r = { 0, 0, 30, 30 };
            for (unsigned int i = 0; i < m_vpMapIcon.size(); i++) {
                DemoMapIcon *icon = m_vpMapIcon[i];
                r.x = DemoDataManager::get().getMobileClient(icon->getMobileClientId())->getX() - 15;
                r.y = DemoDataManager::get().getMobileClient(icon->getMobileClientId())->getY() - 15;
                SDL_RenderCopy(m_pRenderer, icon->render(), icon->Rect(), &r);
            }
        }

        virtual void doUpdate() {
            bool detected = false;
            SDL_Rect r;
            r = { 0, 0, 30, 30 };
            for (unsigned int i = 0; i < m_vpMapIcon.size(); i++) {
                DemoMapIcon *icon = m_vpMapIcon[i];
                r.x = DemoDataManager::get().getMobileClient(icon->getMobileClientId())->getX() - 15;
                r.y = DemoDataManager::get().getMobileClient(icon->getMobileClientId())->getY() - 15;
                if (!detected && SDL_PointInRect(m_sMousePosition, r)) {
                    detected = true;
                    m_vpMapIcon[i]->update(SDL_RelationPoint(&m_sMousePosition, &r));
                } else {
                    m_vpMapIcon[i]->update();
                }
            }
            r = { 0, 0, 400, 400 };
            for (unsigned int i = 0; i < m_vpHexagon.size(); i++) {
                DemoHexagon *hexagon = m_vpHexagon[i];
                r.x = DemoDataManager::get().getBaseStation(hexagon->getBaseStationId())->getX() - 200;
                r.y = DemoDataManager::get().getBaseStation(hexagon->getBaseStationId())->getY() - 200;
                if (!detected 
                    // To avoid distance conflict
                    && SDL_PointInRect(m_sMousePosition,*m_pRect)
                    // Use round area
                    && (SDL_pow( m_sMousePosition.x - r.x - 200 ,2) 
                    + SDL_pow( m_sMousePosition.y - r.y - 200 ,2) 
                    < 200 * 200) ){
                    m_vpHexagon[i]->update(SDL_RelationPoint(&m_sMousePosition, &r));
                } else {
                    m_vpHexagon[i]->update({-10000,-1000 });
                }
            }
        }
    };
}