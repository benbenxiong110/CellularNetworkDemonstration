#pragma once
#include "Include.h"
#include "ButtonBase.h"

namespace CellularNetworkDemonstration {
    class MenuViewSelector : public ButtonBase {
    public:
        MenuViewSelector(SDL_Renderer *renderer, const char* Caption, const int Code)
            :ButtonBase(renderer, 70, 30), m_iSelectorCode(Code) {
            this->m_bActive = false;

            SDL_Texture* origTarget = SDL_GetRenderTarget(m_pRenderer);
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(m_pRenderer, &r, &g, &b, &a);


            m_pUnderLine = SDL_CreateTexture(renderer,
                SDL_PIXELFORMAT_RGBA8888,
                SDL_TEXTUREACCESS_TARGET, 1, 5);
            SDL_SetTextureBlendMode(m_pUnderLine, SDL_BLENDMODE_BLEND);
            SDL_SetRenderTarget(m_pRenderer, m_pUnderLine);
            SDL_SetRenderDrawColor(m_pRenderer, 50, 50, 50, 15);
            SDL_RenderClear(m_pRenderer);
            SDL_SetRenderDrawColor(m_pRenderer, 155, 155, 155, 125);
            SDL_RenderDrawPoint(m_pRenderer, 0, 1);
            SDL_RenderDrawPoint(m_pRenderer, 0, 3);
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 225);
            SDL_RenderDrawPoint(m_pRenderer, 0, 2);
            SDL_RenderPresent(renderer);

            m_pUnderLinePosition = new SDL_Rect{ 0, 25, 70, 5 };

            m_pCaptionText = TTF_RenderTextTexture(m_pRenderer, Caption, 21);
            m_pCaptionPosition = new SDL_Rect;
            int w, h; SDL_QueryTexture(m_pCaptionText, NULL, NULL, &w, &h);
            m_pCaptionPosition->x = 35 - w / 2;
            m_pCaptionPosition->y = 0;
            m_pCaptionPosition->w = w;
            m_pCaptionPosition->h = h;


            // 恢复渲染器状态
            SDL_SetRenderTarget(m_pRenderer, origTarget);
            SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);

        }
        ~MenuViewSelector() {
            // 清理子元素和资源
            if (m_pCaptionText) {
                SDL_DestroyTexture(m_pCaptionText);
            }
            if (m_pUnderLine) {
                SDL_DestroyTexture(m_pUnderLine);
            }
            DELETE_IF_EXIST(m_pCaptionPosition)
        }

        void active() {
            this->m_bActive = true;
        }

        void deactive() {
            if (m_bActive) {
                this->m_bActive = false;
                this->percent = 100;
                this->lastTick = SDL_GetTicks();

            }
        }

        void setActive(bool active) {
            this->m_bActive = active;
        }

        void toggleActive() {
            if (m_bActive) {
                active();
            } else {
                deactive();
            }
        }

        bool isActive() const {
            return this->m_bActive;
        }

        int getSelectorCode() const {
            return this->m_iSelectorCode;
        }
    private:
        SDL_Texture *m_pCaptionText;
        SDL_Rect *m_pCaptionPosition;
        SDL_Texture *m_pUnderLine;
        SDL_Rect *m_pUnderLinePosition;

        bool m_bActive;
        const int m_iSelectorCode;

        // 绘制界面元素
        virtual void doRender() {
            //SDL_SetRenderDrawColor(m_pRenderer, 250, 30, 30, 0);// getRenderAlpha());
            SDL_RenderClear(m_pRenderer);
            SDL_RenderCopy(m_pRenderer, m_pCaptionText, nullptr, m_pCaptionPosition);
            if (m_bActive || m_pState == BUTTON_STATE_DOWN) {
                m_pUnderLinePosition->x = 0;
                m_pUnderLinePosition->w = 70;
                SDL_RenderCopy(m_pRenderer, m_pUnderLine, nullptr, m_pUnderLinePosition);
            } else if (m_pState == BUTTON_STATE_HOVER) {
                m_pUnderLinePosition->w = 2 * getRenderValue(true);
                m_pUnderLinePosition->x = 35 - m_pUnderLinePosition->w / 2;
                SDL_RenderCopy(m_pRenderer, m_pUnderLine, nullptr, m_pUnderLinePosition);
            } else {
                m_pUnderLinePosition->w = 2 * getRenderValue(false);
                m_pUnderLinePosition->x = 35 - m_pUnderLinePosition->w / 2;
                if (m_pUnderLinePosition->x < 35) {
                    SDL_RenderCopy(m_pRenderer, m_pUnderLine, nullptr, m_pUnderLinePosition);
                }
            }
        }

        int percent = 0;
        int lastTick = 0;
        // 背景混合动画
        int getRenderValue(bool wider) {
            const static int IN_DURATION = 150 / 100;//Divided by 100 percents
            const static int OUT_DURATION = 300 / 100;//Divided by 100 percents

            int currentTick = SDL_GetTicks();

            int width, delta;
            if (wider) {
                width = 35;
                if (percent != 100) {
                    delta = ( currentTick - lastTick ) / IN_DURATION;
                    percent += delta;
                    if (percent > 100) {
                        percent = 100;
                    }
                    width = 35 * SDL_sin(percent / 100.0);
                }
            } else {
                width = 0;
                if (percent != 0) {
                    delta = ( currentTick - lastTick ) / OUT_DURATION;
                    percent -= delta;
                    if (percent < 0) {
                        percent = 0;
                    }
                    width = 35 * SDL_sin(percent / 100.0);
                }
            }
            lastTick = currentTick;
            SDL_log(width);
            return width;
        }

        virtual void doAction() {
            SDL_Event* select = new SDL_Event;
            select->type = SDL_USEREVENT;
            select->user.code = m_iSelectorCode;
            SDL_PushEvent(select);
        }
    };
}