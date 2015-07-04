#pragma once
#include "Include.h"
namespace CellularNetworkDemonstration {
    
    class MainBaseStation {
    public:
        enum BaseStationType {
            TYPE_UNKNOWN = 0,
            TYPE_MACRO,
            TYPE_MICRO
        };
        MainBaseStation(int ID):id(ID) {

        }
        ~MainBaseStation() {

        }
        SDL_Texture *draw() {
            return render();
        }
        SDL_Texture *render() {

        }
        int getId() {
            return id;
        }

        BaseStationType getType() const {
            return type;
        }

        const char *getTypeName() const{
            const static char* name_unknown = "未知";
            const static char* name_micro = "微站";
            const static char* name_macro = "宏站";
            switch (type) {
                case CellularNetworkDemonstration::MainBaseStation::TYPE_UNKNOWN:
                    return name_unknown;
                case CellularNetworkDemonstration::MainBaseStation::TYPE_MACRO:
                    return name_macro;
                case CellularNetworkDemonstration::MainBaseStation::TYPE_MICRO:
                    return name_micro;
            }
        }
    private:
        const int id;
        int x;
        int y;
        int height;
        BaseStationType type;
        double radio;
        
        
    };
}