#pragma once
#include "Include.h"
#include "MainBaseStation.h"
#include "MainMobileClient.h"

#include "MainMobilePhone.h"
#include "MainLaptop.h"
#include "MainPDA.h"

namespace CellularNetworkDemonstration {
    class DemoDataManager {
    public:
        static DemoDataManager &get() {
            static DemoDataManager* manager = nullptr;
            if (manager == nullptr) {
                manager = new DemoDataManager();

                // Initialize Data
                manager->addBaseStation();
                manager->addBaseStation();
                manager->addBaseStation();
                manager->addBaseStation();
                manager->addBaseStation();
                manager->addBaseStation();

                manager->addMobileClient(MAIN_MOBILE_CLIENT_LAPTOP);
                manager->addMobileClient(MAIN_MOBILE_CLIENT_MOBILE_PHONE);
                manager->addMobileClient(MAIN_MOBILE_CLIENT_PDA);
                manager->addMobileClient(MAIN_MOBILE_CLIENT_LAPTOP);
                manager->addMobileClient(MAIN_MOBILE_CLIENT_MOBILE_PHONE);
                manager->addMobileClient(MAIN_MOBILE_CLIENT_PDA);

            }
            return *manager;
        }
        
        int addMobileClient(MainMobileClientType type) {
            int id = getNewId();
            MainMobileClient *client;
            switch (type) {
                case CellularNetworkDemonstration::MAIN_MOBILE_CLIENT_MOBILE_PHONE:
                    client = new MainMobilePhone(id);
                    break;
                case CellularNetworkDemonstration::MAIN_MOBILE_CLIENT_LAPTOP:
                    client = new MainLaptop(id);
                    break;
                case CellularNetworkDemonstration::MAIN_MOBILE_CLIENT_PDA:
                    client = new MainPDA(id);
                    break;
            }
            m_vpMobileClientList.push_back(client);
            return id;
        }

        MainMobileClient *getMobileClient(int id) {
            for (unsigned int i = 0; i < m_vpMobileClientList.size(); i++) {
                if (m_vpMobileClientList[i]->getId() == id) {
                    return m_vpMobileClientList[i];
                }
            }
            return nullptr;

        }

        int addBaseStation() {
            int id = getNewId();
            MainBaseStation *baseStation = new MainBaseStation(id);
            m_vpBaseStationList.push_back(baseStation);
            return id;
        }

        MainBaseStation *getBaseStation(int id) {
            for (unsigned int i = 0; i < m_vpBaseStationList.size(); i++) {
                if (m_vpBaseStationList[i]->getId() == id) {
                    return m_vpBaseStationList[i];
                }
            }
            return nullptr;
        }

        vector<MainBaseStation *>& getBaseStationList() {
            return m_vpBaseStationList;
        }

        vector<MainMobileClient *>& getMobileClientList() {
            return m_vpMobileClientList;
        }

    private:
        DemoDataManager() { }
        int getNewId() {
            static int i = 0;
            return i++;
        }
        vector<MainBaseStation *> m_vpBaseStationList;
        vector<MainMobileClient *> m_vpMobileClientList;
        
    };
}
