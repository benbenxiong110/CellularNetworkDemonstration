#pragma once
#include "ButtonBase.h"
#include "DemoTextureManager.h"
#include <sstream>
#include "DemoDataManager.h"

namespace CellularNetworkDemonstration {
    class DemoAttributeListItem :public ButtonBase {
    public:

        DemoAttributeListItem(SDL_Renderer *renderer, int clientId)
            :ButtonBase(renderer, 30, 30), m_iMobileClientID(clientId) {
            SDL_Texture* origTarget = SDL_GetRenderTarget(m_pRenderer);
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(m_pRenderer, &r, &g, &b, &a);
            

            m_pIconRect = new SDL_Rect{ 4, 4, 20, 20 };

            SDL_SetRenderTarget(m_pRenderer, origTarget);
            SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);

        }

        ~DemoAttributeListItem() {
            DELETE_IF_EXIST(m_pIconRect)
        }

    private:
        const int m_iMobileClientID;

        SDL_Rect *m_pIconRect;


        virtual void doRender() {
            SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
            SDL_RenderClear(m_pRenderer);
            SDL_SetRenderDrawColor(m_pRenderer, 180, 120, 40, getRenderAlpha());
            for (int i = 0; i < 30; i += 2) {
                SDL_RenderDrawLine(m_pRenderer, ( i < 15 ? 15 - i : i - 15 ), i, ( i < 15 ? 15 + i : i ), i);
            }
            SDL_RenderCopy(m_pRenderer, DemoDataManager::get().getMobileClient(m_iMobileClientID)->render(m_pRenderer), nullptr, nullptr);
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
            minimize->user.code = SDL_DEMO_SIDEBAR_MOBILE_CLIENT;
            int *id = new int(m_iMobileClientID);
            minimize->user.data1 = id;
            SDL_PushEvent(minimize);
            m_pState = BUTTON_STATE_NORMAL;
        }


    };
}
