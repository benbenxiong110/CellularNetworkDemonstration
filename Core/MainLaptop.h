#pragma once
#include "MainMobileClient.h"
namespace CellularNetworkDemonstration {
    class MainLaptop : public MainMobileClient {
    public:
        MainLaptop(int ID) :MainMobileClient(MAIN_MOBILE_CLIENT_LAPTOP, ID) {

        }
    private:
    };
}