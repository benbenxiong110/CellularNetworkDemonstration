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
            SDL_Color color = { 255, 255, 20, 100 };
            hexagon = new DemoHexagon(renderer, &color);

            vector<MainMobileClient *>& mobileClientList
                = DemoDataManager::get().getMobileClientList();
            for (unsigned int i = 0; i < mobileClientList.size(); i++) {
                m_vpMapIcon.push_back(new DemoMapIcon(m_pRenderer, mobileClientList[i]->getId()));
            }

        }

        ~DemoMap() {
            // 清理子元素和资源
            DELETE_IF_EXIST(hexagon);

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
        DemoHexagon *hexagon;
        vector<DemoMapIcon *>m_vpMapIcon;

        // 绘制界面元素
        virtual void doRender() {
            SDL_SetRenderDrawColor(m_pRenderer, 20, 220, 120, 255);
            SDL_RenderClear(m_pRenderer);
            SDL_Texture *hexagonTexture = hexagon->render();
            int em = 200;
            SDL_Rect r = { 0, 0, 2 * em, 2 * em };
            for (int i = 0; i < 3; i++) {
                r.y = SDL_static_cast(int, 1.5 * em * i - 0.5 * em);
                for (int j = 0; j < 3; j++) {
                    r.x = SDL_static_cast(int, -( i % 2 == 0 ? em : 0.14 * em ) + j * 1.72 * em);
                    SDL_RenderCopy(m_pRenderer, hexagonTexture, nullptr, &r);
                }
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
        }
    };
}