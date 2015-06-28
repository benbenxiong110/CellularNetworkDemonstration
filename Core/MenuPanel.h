#pragma once
#include <SDL.h>
namespace CellularNetworkDemonstration {

    class MenuPanel {
    public:
        MenuPanel();
        ~MenuPanel();
        SDL_Texture *render() {
            
            return m_pTexture;
        }
    private:
        SDL_Texture *m_pTexture;
    };
}
