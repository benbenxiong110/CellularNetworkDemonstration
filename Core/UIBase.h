#pragma once
#include "Include.h"

#define DELETE_IF_EXIST(POINTER) if(POINTER){delete (POINTER);}

namespace CellularNetworkDemonstration {
    class UIBase {
    public:
        UIBase(SDL_Renderer *renderer, int width, int height);
        virtual ~UIBase();

        SDL_Texture *render() {
            // 储存渲染器状态

            SDL_Texture* origTarget = SDL_GetRenderTarget(m_pRenderer);
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(m_pRenderer, &r, &g, &b, &a);

            // 设置渲染器，进行当前界面元素的绘制
            SDL_SetRenderTarget(m_pRenderer, m_pTexture);
            // 实际进行绘制
            renderUI();
            SDL_RenderPresent(m_pRenderer);

            // 恢复渲染器状态
            SDL_SetRenderTarget(m_pRenderer, origTarget);
            SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);

            return m_pTexture;
        }

        SDL_Rect * Rect() const {
            return m_pRect;
        }

        int getWidth() const{
            return m_pRect->w;
        }
        int getHeight() const {
            return m_pRect->h;

        }
    protected:
        SDL_Renderer *m_pRenderer;
        SDL_Texture *m_pTexture;
        SDL_Rect *m_pRect;
        virtual void renderUI() = 0;
    };

}


