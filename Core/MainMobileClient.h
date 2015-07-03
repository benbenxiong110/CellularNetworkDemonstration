#pragma once
#include "Include.h"
namespace CellularNetworkDemonstration {

    class MainMobileClient {
    public:
        MainMobileClient() {

        }
        ~MainMobileClient() {

        }
        SDL_Texture *draw() {
            return render();
        }
        SDL_Texture *render() {

        }
        string getId() const{
            return id;
        }
        string getModel() const {
            return model;
        }
    private:
        string id;
        string model;
        double velocity;
        int trace;
        int frequency;
        int x;
        int y;

    };
}