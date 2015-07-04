#pragma once
#include "ButtonBase.h"
#include "DemoTextureManager.h"
#include <sstream>

namespace CellularNetworkDemonstration {
    class DemoBaseStationListItem :public ButtonBase {
    public:
        DemoBaseStationListItem(SDL_Renderer *renderer, int baseStationID)
            :ButtonBase(renderer, 185, 20), m_iBaseStationID(baseStationID) {
            SDL_Texture* origTarget = SDL_GetRenderTarget(m_pRenderer);
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(m_pRenderer, &r, &g, &b, &a);
            m_pBaseStationIconPosition = new SDL_Rect{ 5, 0, 20, 20 };
            

            string s;
            stringstream ss;
            ss << DemoDataManager::get().getMobileClient(m_iBaseStationID)->getId();
            ss >> s;
            s = "基站 " + s;
            SDL_log(s.c_str());
            SDL_Color color = SDL_Color{ 30, 30, 30, 180 };
            m_pListText = TTF_RenderTextTexture(m_pRenderer, s.c_str(), 16, &color);
            int w, h;
            SDL_QueryTexture(m_pListText, nullptr, nullptr, &w, &h);
            m_pListTextPosition = new SDL_Rect{ 35, 0, w, h };

            // 恢复渲染器状态
            SDL_SetRenderTarget(m_pRenderer, origTarget);
            SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);

        }
        ~DemoBaseStationListItem() {
            // 清理子元素和资源
            DELETE_IF_EXIST(m_pBaseStationIconPosition)
                DELETE_IF_EXIST_TEXTURE(m_pListText)
                DELETE_IF_EXIST(m_pListTextPosition)
        }

    private:
        const int m_iBaseStationID;

        SDL_Rect *m_pBaseStationIconPosition;
        SDL_Texture *m_pListText;
        SDL_Rect *m_pListTextPosition;

        // 绘制界面元素
        virtual void doRender() {
            SDL_SetRenderDrawColor(m_pRenderer, 20, 20, 20, getRenderAlpha());
            SDL_RenderClear(m_pRenderer);
            SDL_RenderCopy(m_pRenderer, DemoTextureManager::get().getTexture(m_pRenderer,"icon-base-station-small.png"), nullptr, m_pBaseStationIconPosition);
            SDL_RenderCopy(m_pRenderer, m_pListText, nullptr, m_pListTextPosition);

        }



        // 背景混合动画
        int percent = 0;
        int lastTick = 0;
        int currentTick;
        int getRenderAlpha() {

            const static int IN_DURATION = 200 / 100;//Divided by 100 percents
            const static int OUT_DURATION = 400 / 100;//Divided by 100 percents

            currentTick = SDL_GetTicks();

            int alpha, delta;
            switch (m_pState) {
                case BUTTON_STATE_NORMAL:
                    delta = ( currentTick - lastTick ) / OUT_DURATION;
                    percent -= delta;
                    if (percent < 0) {
                        percent = 0;
                    }
                    // 缓动曲线设置为正弦
                    alpha = SDL_static_cast(int, 160 * SDL_sin(percent / 100.0));
                    break;
                case BUTTON_STATE_HOVER:
                    delta = ( currentTick - lastTick ) / IN_DURATION;
                    percent += delta;
                    if (percent > 100) {
                        percent = 100;
                    }
                    // 缓动曲线设置为正弦
                    alpha = SDL_static_cast(int, 160 * SDL_sin(percent / 100.0));
                    break;
                case BUTTON_STATE_DOWN:
                    alpha = 225;
                    break;
                default:
                    break;
            }
            lastTick = currentTick;
            return alpha;
        }

        virtual void doAction() {
            SDL_Event* minimize = new SDL_Event;
            minimize->type = SDL_USEREVENT;
            minimize->user.code = SDL_DEMO_SIDEBAR_BASE_STATION;
            int *id = new int(m_iBaseStationID);
            minimize->user.data1 = id;
            SDL_PushEvent(minimize);
            m_pState = BUTTON_STATE_NORMAL;

        }

        
    };
}
