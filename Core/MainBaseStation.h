#pragma once
#include "Include.h"
namespace CellularNetworkDemonstration {
    
    class MainBaseStation {
    public:
        enum BaseStationType {

        };
        MainBaseStation() {

        }
        ~MainBaseStation() {

        }
        SDL_Texture *draw() {
            return render();
        }
        SDL_Texture *render() {

        }
    private:
        int x;
        int y;
        int height;
        BaseStationType type;
        double radio;
        
        
    };
}