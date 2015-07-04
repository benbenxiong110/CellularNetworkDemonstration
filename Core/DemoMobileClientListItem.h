#pragma once
#include "ButtonBase.h"

namespace CellularNetworkDemonstration {
    class DemoMoblieClientListItem :public ButtonBase {
    public:
        DemoMoblieClientListItem(SDL_Renderer *renderer, int mobileClientID)
            :ButtonBase(renderer, 185, 20), m_iMobileClientID(mobileClientID) {
            SDL_Texture* origTarget = SDL_GetRenderTarget(m_pRenderer);
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(m_pRenderer, &r, &g, &b, &a);



            m_pMinimizeIcon = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 11, 10);
            SDL_SetTextureBlendMode(m_pMinimizeIcon, SDL_BLENDMODE_BLEND);
            SDL_SetRenderTarget(m_pRenderer, m_pMinimizeIcon);
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 0);
            SDL_RenderClear(m_pRenderer);
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            SDL_RenderDrawLine(renderer, 0, 0, 9, 9);
            SDL_RenderDrawLine(renderer, 1, 0, 10, 9);
            SDL_RenderDrawLine(renderer, 9, 0, 0, 9);
            SDL_RenderDrawLine(renderer, 10, 0, 1, 9);
            SDL_RenderPresent(m_pRenderer);
            m_pMinimizeIconPosition = new SDL_Rect{ 17, 5, 11, 10 };

            // 恢复渲染器状态
            SDL_SetRenderTarget(m_pRenderer, origTarget);
            SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);

        }
        ~DemoMoblieClientListItem() {
            // 清理子元素和资源
            if (m_pMinimizeIcon) {
                SDL_DestroyTexture(m_pMinimizeIcon);
            }
            DELETE_IF_EXIST(m_pMinimizeIconPosition)
        }

    private:
        const int m_iMobileClientID;

        SDL_Texture *m_pMinimizeIcon;
        SDL_Rect *m_pMinimizeIconPosition;

        // 绘制界面元素
        virtual void doRender() {
            switch (DemoDataManager::get().getMobileClient(m_iMobileClientID)->getClientType()) {
                case MAIN_MOBILE_CLIENT_LAPTOP:
                    SDL_SetRenderDrawColor(m_pRenderer, 80, 80, 10, getRenderAlpha());
                    break;
                case MAIN_MOBILE_CLIENT_MOBILE_PHONE:
                    SDL_SetRenderDrawColor(m_pRenderer, 10, 80, 80, getRenderAlpha());
                    break;
                case MAIN_MOBILE_CLIENT_PDA:
                    SDL_SetRenderDrawColor(m_pRenderer, 80, 10, 80, getRenderAlpha());
                    break;
            }
            SDL_RenderClear(m_pRenderer);
            SDL_RenderCopy(m_pRenderer, m_pMinimizeIcon, nullptr, m_pMinimizeIconPosition);
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
