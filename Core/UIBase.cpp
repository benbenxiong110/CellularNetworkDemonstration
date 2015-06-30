#include "UIBase.h"

namespace CellularNetworkDemonstration {
    UIBase::UIBase(SDL_Renderer *renderer, int width, int height) {
        m_pRenderer = renderer;
        m_pTexture = SDL_CreateTexture(m_pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 800, 150);
        SDL_SetTextureBlendMode(m_pTexture, SDL_BLENDMODE_BLEND);
        m_pRect = new SDL_Rect;

        m_pRect->x = 0;
        m_pRect->y = 0;
        m_pRect->w = width;
        m_pRect->h = height;
    }


    UIBase::~UIBase() {
        if (m_pTexture) {
            SDL_DestroyTexture(m_pTexture);
        }
        DELETE_IF_EXIST(m_pRect)
    }


}

