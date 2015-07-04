#pragma once
#include "MainMobileClient.h"
namespace CellularNetworkDemonstration {
    class MainMobilePhone : public MainMobileClient {
    public:
        MainMobilePhone(int ID) :MainMobileClient(MAIN_MOBILE_CLIENT_MOBILE_PHONE, ID) {

        }
    private:
    };
}