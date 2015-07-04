#pragma once
#include "Include.h"
namespace CellularNetworkDemonstration {
    enum MainMobileClientType {
        MAIN_MOBILE_CLIENT_MOBILE_PHONE,
        MAIN_MOBILE_CLIENT_LAPTOP,
        MAIN_MOBILE_CLIENT_PDA
    };

    class MainMobileClient {
    public:
        ~MainMobileClient() {

        }
        SDL_Texture *draw() {
            return render();
        }
        SDL_Texture *render() {

        }

        int getId() const {
            return id;
        }

        string getUuid() const {
            return uuid;
        }
        string getModel() const {
            return model;
        }

        MainMobileClientType getClientType() const {
            return clientType;
        }

    protected:
        MainMobileClient(MainMobileClientType cliType, int ID)
            :clientType(cliType), id(ID) {

        }
        const MainMobileClientType clientType;
        const int id;
        string uuid;
        string model;
        double velocity;
        int trace;
        int frequency;
        int x;
        int y;

    };
}