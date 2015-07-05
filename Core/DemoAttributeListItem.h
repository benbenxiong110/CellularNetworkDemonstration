#pragma once
#include "ButtonBase.h"
#include "DemoTextureManager.h"
#include <sstream>
#include "DemoDataManager.h"

namespace CellularNetworkDemonstration {
    class DemoAttributeListItem :public ButtonBase {
    public:
        enum DemoAttributeType {
            ATTRIBUTE_NORMAL,
            ATTRIBUTE_TYPE_KEYBOARE,
            ATTRIBUTE_TYPE_SCREEN,
            ATTRIBUTE_TYPE_CHIPSET
        };

        DemoAttributeListItem(SDL_Renderer *renderer, DemoAttributeType type, int clientId)
            :ButtonBase(renderer, 185, 20), m_eType(type), m_iMobileClientID(clientId) {
            SDL_Texture* origTarget = SDL_GetRenderTarget(m_pRenderer);
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(m_pRenderer, &r, &g, &b, &a);

            m_pListTexture = SDL_CreateTexture(m_pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, getWidth(), getHeight());
            SDL_SetTextureBlendMode(m_pListTexture, SDL_BLENDMODE_BLEND);
            SDL_SetRenderTarget(m_pRenderer, m_pListTexture);
            SDL_SetRenderDrawColor(m_pRenderer, 40, 60, 80, 220);
            SDL_RenderClear(m_pRenderer);

            SDL_Rect rect;
            SDL_Texture *texture;
            string s;
            stringstream ss;
            switch (m_eType) {
                case ATTRIBUTE_TYPE_CHIPSET:
                    ss << "移动台" << DemoDataManager::get().getMobileClient(m_iMobileClientID)->getId() << "的芯片信息";
                    break;
                case ATTRIBUTE_TYPE_KEYBOARE:
                    ss << "移动台" << DemoDataManager::get().getMobileClient(m_iMobileClientID)->getId() << "的键盘信息";
                    break;
                case ATTRIBUTE_TYPE_SCREEN:
                    ss << "移动台" << DemoDataManager::get().getMobileClient(m_iMobileClientID)->getId() << "的显示屏信息";
                    break;
                default:
                    break;
            }
            s = ss.str();
            int w, h;

            rect = { 0, 0, 80, 20 };

            SDL_Color color = { 220, 220, 220, 180 };
            texture = TTF_RenderTextTexture(m_pRenderer, s.c_str(), 16, &color);
            SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
            rect = { 5, -2, w, h };
            SDL_RenderCopy(m_pRenderer, texture, nullptr, &rect);
            SDL_DestroyTexture(texture);

            SDL_RenderPresent(m_pRenderer);

            SDL_SetRenderTarget(m_pRenderer, origTarget);
            SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);

        }

        DemoAttributeListItem(SDL_Renderer *renderer, string name, string value)
            :ButtonBase(renderer, 185, 20), m_eType(ATTRIBUTE_NORMAL), m_iMobileClientID(0) {
            SDL_Texture* origTarget = SDL_GetRenderTarget(m_pRenderer);
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(m_pRenderer, &r, &g, &b, &a);

            m_pListTexture = SDL_CreateTexture(m_pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, getWidth(), getHeight());
            SDL_SetTextureBlendMode(m_pListTexture, SDL_BLENDMODE_BLEND);
            SDL_SetRenderTarget(m_pRenderer, m_pListTexture);
            SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
            SDL_RenderClear(m_pRenderer);

            SDL_Rect rect;
            SDL_Texture *texture;
            string s;
            stringstream ss;
            SDL_Color color;
            int w, h;

            rect = { 0, 0, 80, 20 };
            SDL_SetRenderDrawColor(m_pRenderer, 120, 80, 10, 170);
            SDL_RenderFillRect(m_pRenderer, &rect);

            color = { 220, 220, 220, 180 };
            texture = TTF_RenderTextTexture(m_pRenderer, name.c_str(), 16, &color);
            SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
            rect = { 40 - w / 2, -2, w, h };
            SDL_RenderCopy(m_pRenderer, texture, nullptr, &rect);
            SDL_DestroyTexture(texture);

            color = { 30, 30, 30, 180 };
            texture = TTF_RenderTextTexture(m_pRenderer, value.c_str(), 16, &color);
            SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
            rect = { 135 - w / 2, -2, w, h };
            SDL_RenderCopy(m_pRenderer, texture, nullptr, &rect);
            SDL_DestroyTexture(texture);


            SDL_SetRenderTarget(m_pRenderer, origTarget);
            SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);
        }
        ~DemoAttributeListItem() {
            DELETE_IF_EXIST_TEXTURE(m_pListTexture)
        }

    private:
        const int m_iMobileClientID;
        const DemoAttributeType m_eType;

        SDL_Texture *m_pListTexture;


        virtual void doRender() {
            SDL_SetRenderDrawColor(m_pRenderer, 40, 40, 40, getRenderAlpha());
            if (m_iMobileClientID != 0) {
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

            }
            SDL_RenderClear(m_pRenderer);
            SDL_RenderCopy(m_pRenderer, m_pListTexture, nullptr, nullptr);
        }



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
                    alpha = SDL_static_cast(int, 160 * SDL_sin(percent / 100.0));
                    break;
                case BUTTON_STATE_HOVER:
                    delta = ( currentTick - lastTick ) / IN_DURATION;
                    percent += delta;
                    if (percent > 100) {
                        percent = 100;
                    }
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
            switch (m_eType) {
                case ATTRIBUTE_TYPE_SCREEN:
                    minimize->user.code = SDL_DEMO_SIDEBAR_SCREEN;

                    break;
                case ATTRIBUTE_TYPE_KEYBOARE:
                    minimize->user.code = SDL_DEMO_SIDEBAR_KEYBOARD;
                    break;
                case ATTRIBUTE_TYPE_CHIPSET:
                    minimize->user.code = SDL_DEMO_SIDEBAR_CHIPSET;
                    break;
                case ATTRIBUTE_NORMAL: default:
                    return;
                    break;
            }
            int *id = new int(m_iMobileClientID);
            minimize->user.data1 = id;
            SDL_PushEvent(minimize);
            m_pState = BUTTON_STATE_NORMAL;
        }


    };
}
