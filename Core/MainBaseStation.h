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
        MainBaseStation(int ID, int x = 0, int y = 0, int h = 100,
            int circle = 3000, int speed = 2000,
            BaseStationType type = TYPE_UNKNOWN) :id(ID) {
            this->x = x;
            this->y = y;
            this->height = h;
            this->circle = circle;
            this->speed = speed;
            this->type = type;
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

        const string getTypeName() const {
            const static string name_unknown = "δ֪";
            const static string name_micro = "΢վ";
            const static string name_macro = "��վ";
            switch (type) {
                case CellularNetworkDemonstration::MainBaseStation::TYPE_UNKNOWN:
                    return name_unknown;
                case CellularNetworkDemonstration::MainBaseStation::TYPE_MACRO:
                    return name_macro;
                case CellularNetworkDemonstration::MainBaseStation::TYPE_MICRO:
                    return name_micro;
            } return name_unknown;
        }
        int getX() const {
            return x;
        }
        int getY() const {
            return y;
        }
        int getHeight() const {
            return height;
        }
        int getCircle() const {
            return circle;
        }
        int getSpeed() const {
            return speed;
        }
    private:
        const int id;
        int x;
        int y;
        int height;
        BaseStationType type;
        int circle;
        int speed;

    };
}