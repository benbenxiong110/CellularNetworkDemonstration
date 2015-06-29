#pragma once
#include <SDL.h>
namespace CellularNetworkDemonstration {

    class MenuPanel {
    public:
        MenuPanel(SDL_Renderer *renderer);
        ~MenuPanel();
        SDL_Texture *render() {
            //SDL_UpdateTexture(m_pTexture,m_pRect,)
            
            return m_pTexture;
        }

        
        SDL_Rect * Rect() const {
            return m_pRect;
        }
    private:
        SDL_Renderer *m_pRenderer;
        SDL_Texture *m_pTexture;
        SDL_Rect *m_pRect;
    };
}
