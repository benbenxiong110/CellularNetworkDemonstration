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
                /*
                manager->addBaseStation(getHexagonPositionX(0, 0),
                getHexagonPositionY(0, 0), 200, 2000, 3000, MainBaseStation::TYPE_MICRO);*/
                manager->addBaseStation(getHexagonPositionX(0, 1),
                    getHexagonPositionY(0, 1), 260, 2000, 2300, MainBaseStation::TYPE_MACRO);
                manager->addBaseStation(getHexagonPositionX(0, 2),
                    getHexagonPositionY(0, 2), 300, 2000, 2200, MainBaseStation::TYPE_MICRO);
                manager->addBaseStation(getHexagonPositionX(1, 0),
                    getHexagonPositionY(1, 0), 220, 2000, 3600, MainBaseStation::TYPE_UNKNOWN);
                manager->addBaseStation(getHexagonPositionX(1, 2),
                    getHexagonPositionY(1, 1), 100, 2000, 2100, MainBaseStation::TYPE_MACRO);
                //manager->addBaseStation(getHexagonPositionX(0, 0), 
                //    getHexagonPositionY(0, 0), 140, 2000, 4500, MainBaseStation::TYPE_MICRO);
                int id;
                MainMobileClient *client;


                id = manager->addMobileClient(MAIN_MOBILE_CLIENT_LAPTOP, 100, 200);
                client = manager->getMobileClient(id);
                client->setModel("Model-04");
                client->setUuid("18292870000");
                client->setFrequency(16000);
                client->setChip(MainChip::CHIP_TYPE_X86, 200, 200, 32000);
                client->setKeyboard(106, 35, 17, "银色");
                client->setScreen(MainScreen::SCREEN_TYPE_NO_TOUCH, 30, 10, 64000, 1080, 1920);


                id = manager->addMobileClient(MAIN_MOBILE_CLIENT_MOBILE_PHONE, 300, 180);
                client = manager->getMobileClient(id);
                client->setModel("Model-03");
                client->setUuid("13621340000");
                client->setFrequency(18000);
                client->setChip(MainChip::CHIP_TYPE_ARM, 200, 200, 32000);
                client->setKeyboard(106, 35, 17, "黄色");
                client->setScreen(MainScreen::SCREEN_MULTI_C_TOUCH, 30, 10, 64000, 1080, 1920);


                id = manager->addMobileClient(MAIN_MOBILE_CLIENT_PDA, 400, 270);
                client = manager->getMobileClient(id);
                client->setModel("Model-02");
                client->setUuid("13122170000");
                client->setFrequency(36000);
                client->setChip(MainChip::CHIP_TYPE_POWER_PC, 200, 200, 32000);
                client->setKeyboard(106, 35, 17, "黑色");
                client->setScreen(MainScreen::SCREEN_R_TOUCH, 30, 10, 64000, 1080, 1920);


                id = manager->addMobileClient(MAIN_MOBILE_CLIENT_LAPTOP, 300, 220);
                client = manager->getMobileClient(id);
                client->setModel("Model-01");
                client->setUuid("15322870000");
                client->setFrequency(16000);
                client->setChip(MainChip::CHIP_TYPE_AMD64, 200, 200, 32000);
                client->setKeyboard(106, 35, 17, "棕色");
                client->setScreen(MainScreen::SCREEN_C_TOUCH, 30, 10, 64000, 1080, 1920);


                id = manager->addMobileClient(MAIN_MOBILE_CLIENT_MOBILE_PHONE, 420, 320);
                client = manager->getMobileClient(id);
                client->setModel("Model-05");
                client->setUuid("15987270000");
                client->setFrequency(16000);
                client->setChip(MainChip::CHIP_TYPE_ARM, 200, 200, 32000);
                client->setKeyboard(106, 35, 17, "绿色");
                client->setScreen(MainScreen::SCREEN_MULTI_C_TOUCH, 30, 10, 64000, 1080, 1920);


                id = manager->addMobileClient(MAIN_MOBILE_CLIENT_PDA, 300, 150);
                client = manager->getMobileClient(id);
                client->setModel("Model-06");
                client->setUuid("13002210000");
                client->setFrequency(16000);
                client->setChip(MainChip::CHIP_TYPE_IA64, 200, 200, 32000);
                client->setKeyboard(106, 35, 17, "灰色");
                client->setScreen(MainScreen::SCREEN_C_TOUCH, 30, 10, 64000, 1080, 1920);

            }
            return *manager;
        }

        int addMobileClient(MainMobileClientType type, int x, int y) {
            int id = getNewId(2);
            MainMobileClient *client;
            switch (type) {
                case CellularNetworkDemonstration::MAIN_MOBILE_CLIENT_MOBILE_PHONE:
                    client = new MainMobilePhone(id, x, y);
                    break;
                case CellularNetworkDemonstration::MAIN_MOBILE_CLIENT_LAPTOP:
                    client = new MainLaptop(id, x, y);
                    break;
                case CellularNetworkDemonstration::MAIN_MOBILE_CLIENT_PDA:
                    client = new MainPDA(id, x, y);
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

        int addBaseStation(int x = 0, int y = 0, int h = 100,
            int circle = 3000, int speed = 2000,
            MainBaseStation::BaseStationType type = MainBaseStation::TYPE_UNKNOWN) {
            int id = getNewId(1);
            MainBaseStation *baseStation = new MainBaseStation(id, x, y, h, circle, speed, type);
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

        void updateValue() {
            for (unsigned int i = 0; i < m_vpMobileClientList.size(); i++) {
                m_vpMobileClientList[i]->update();
                int n = 0;

                for (unsigned int j = 0; j < m_vpBaseStationList.size(); j++) {
                    if (SDL_pow(m_vpMobileClientList[i]->getX() - m_vpBaseStationList[j]->getX(), 2)
                        + SDL_pow(m_vpMobileClientList[i]->getY() - m_vpBaseStationList[j]->getY(), 2) < 200 * 200) {
                        n++;
                    }
                }
                m_vpMobileClientList[i]->setConnection(n);


            }

        }
    private:
        DemoDataManager() {
        }
        int getNewId(int val) {
            static int i = 0;
            static int j = 0;
            static int k = 0;
            switch (val) {
                case 1:
                    return ++j;
                case 2:
                    return ++k;

                default:
                    return ++i;
            }
        }

        static inline  int getHexagonPositionX(int row, int col) {
            int em = 200;
            return SDL_static_cast(int, -( row % 2 == 0 ? em : 0.14 * em ) + col * 1.72 * em);

        }
        static inline int getHexagonPositionY(int row, int col) {
            int em = 200;
            return SDL_static_cast(int, 1.5 * em * row + 0.5 * em);

        }

        vector<MainBaseStation *> m_vpBaseStationList;
        vector<MainMobileClient *> m_vpMobileClientList;

    };
}
