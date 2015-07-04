#pragma once
#include "MainMobileClient.h"
namespace CellularNetworkDemonstration {
    class MainPDA : public MainMobileClient {
    public:
        MainPDA(int ID) :MainMobileClient(MAIN_MOBILE_CLIENT_PDA,ID) {

        }
    private:
    };
}