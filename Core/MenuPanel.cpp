#include "MenuPanel.h"
#include <SDL.h>

namespace CellularNetworkDemonstration {
    MenuPanel::MenuPanel(SDL_Renderer *renderer) {
        m_pRenderer = renderer;
        SDL_CreateTexture(m_pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, 800, 150);
        m_pRect = new SDL_Rect;
        m_pRect->x = 0;
        m_pRect->y = 0;
        m_pRect->w = 800;
        m_pRect->h = 150;
        SDL_SetRenderDrawColor(m_pRenderer, 20, 120, 220, 1);
        SDL_SetRenderTarget(m_pRenderer, m_pTexture);
        SDL_RenderClear(renderer);
    }


    MenuPanel::~MenuPanel() {
        if (m_pTexture) {
            SDL_DestroyTexture(m_pTexture);
        }
        if (m_pRect) {
            delete m_pRect;

        }
    }

}