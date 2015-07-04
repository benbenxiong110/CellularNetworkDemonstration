#pragma once
#include "ButtonBase.h"
#include "DemoTextureManager.h"

namespace CellularNetworkDemonstration {
    class DemoBaseStationListItem :public ButtonBase {
    public:
        DemoBaseStationListItem(SDL_Renderer *renderer, int baseStationID)
            :ButtonBase(renderer, 185, 20), m_iBaseStationID(baseStationID) {
            SDL_Texture* origTarget = SDL_GetRenderTarget(m_pRenderer);
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(m_pRenderer, &r, &g, &b, &a);
            m_pBaseStationIconPosition = new SDL_Rect{ 5, 0, 20, 20 };
            
            // 恢复渲染器状态
            SDL_SetRenderTarget(m_pRenderer, origTarget);
            SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);

        }
        ~DemoBaseStationListItem() {
            // 清理子元素和资源
            DELETE_IF_EXIST(m_pBaseStationIconPosition)
        }

    private:
        const int m_iBaseStationID;

        SDL_Rect *m_pBaseStationIconPosition;

        // 绘制界面元素
        virtual void doRender() {
            SDL_SetRenderDrawColor(m_pRenderer, 20, 20, 20, getRenderAlpha());
            SDL_RenderClear(m_pRenderer);
            SDL_RenderCopy(m_pRenderer, DemoTextureManager::get().getTexture(m_pRenderer,"icon-base-station-small.png"), nullptr, m_pBaseStationIconPosition);
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
            //SDL_Event* minimize = new SDL_Event;
            //minimize->type = SDL_USEREVENT;
            //minimize->user.code = SDL_MINIMIZE;
            //SDL_PushEvent(minimize);

            m_pState = BUTTON_STATE_NORMAL;
        }

        
    };
}
