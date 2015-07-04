#pragma once
#include "ButtonBase.h"
#include "DemoTextureManager.h"

namespace CellularNetworkDemonstration {
    class DemoMoblieClientListItem :public ButtonBase {
    public:
        DemoMoblieClientListItem(SDL_Renderer *renderer, int mobileClientID):ButtonBase(renderer, 185, 20), m_iMobileClientID(mobileClientID) {
            SDL_Texture* origTarget = SDL_GetRenderTarget(m_pRenderer);
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(m_pRenderer, &r, &g, &b, &a);

            /*if (!s_pListIcon_MoiblePhone) {
                s_pListIcon_MoiblePhone = IMG_LoadTexture(m_pRenderer, "icon-mobile-phone-small.png");
            }
            if (!s_pListIcon_Laptop) {
                s_pListIcon_Laptop = IMG_LoadTexture(m_pRenderer, "icon-mobile-phone-small.png");
            }
            if (!s_pListIcon_PDA) {
                s_pListIcon_PDA = IMG_LoadTexture(m_pRenderer, "icon-mobile-phone-small.png");
            }*/
            if (!s_pListIconPosition) {
                s_pListIconPosition = new SDL_Rect{ 5, 0, 20, 20 };
            }
            // 恢复渲染器状态
            SDL_SetRenderTarget(m_pRenderer, origTarget);
            SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);
        }
        ~DemoMoblieClientListItem() {
            // 清理子元素和资源
            //DELETE_IF_EXIST_TEXTURE(m_pListIcon_Laptop)
            //DELETE_IF_EXIST_TEXTURE(m_pListIcon_MoiblePhone)
            //DELETE_IF_EXIST_TEXTURE(m_pListIcon_PDA)
        }

    private:
        const int m_iMobileClientID;/*


        static SDL_Texture *s_pListIcon_MoiblePhone;
        static SDL_Texture *s_pListIcon_Laptop;
        static SDL_Texture *s_pListIcon_PDA;*/
        SDL_Rect *s_pListIconPosition;

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
            switch (DemoDataManager::get().getMobileClient(m_iMobileClientID)->getClientType()) {
                case MAIN_MOBILE_CLIENT_LAPTOP:
                    SDL_RenderCopy(m_pRenderer, DemoTextureManager::get().getTexture(m_pRenderer,"icon-mobile-phone-small.png"), nullptr, s_pListIconPosition);
                    break;
                case MAIN_MOBILE_CLIENT_MOBILE_PHONE:
                    SDL_RenderCopy(m_pRenderer, DemoTextureManager::get().getTexture(m_pRenderer, "icon-mobile-phone-small.png"), nullptr, s_pListIconPosition);
                    break;
                case MAIN_MOBILE_CLIENT_PDA:
                    SDL_RenderCopy(m_pRenderer, DemoTextureManager::get().getTexture(m_pRenderer, "icon-mobile-phone-small.png"), nullptr, s_pListIconPosition);
                    break;
            }
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
                    delta = (currentTick - lastTick) / OUT_DURATION;
                    percent -= delta;
                    if (percent < 0) {
                        percent = 0;
                    }
                    // 缓动曲线设置为正弦
                    alpha = SDL_static_cast(int, 160 * SDL_sin(percent / 100.0));
                    break;
                case BUTTON_STATE_HOVER:
                    delta = (currentTick - lastTick) / IN_DURATION;
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
