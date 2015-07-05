#pragma once
#include "Include.h"
#include "MainKeyboard.h"
#include "MainChip.h"
#include "MainScreen.h"
#include "MainChip.h"
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
        SDL_Texture *draw(SDL_Renderer *renderer) {
            return render(renderer);
        }
        virtual SDL_Texture *render(SDL_Renderer *renderer) = 0;

        void update() {
            switch (trace) {
                case 0:
                    trace_0_update();
                    break;
                case 1:
                    trace_1_update();
                    break;
                case 2:
                    trace_2_update();
                    break;
                case 3:
                    trace_3_update();
                    break;
                case 4:
                    trace_4_update();
                    break;
                case 5:
                    trace_5_update();
                    break;
                case 6:
                    trace_6_update();
                    break;

                default:
                    break;
            }
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

        void setKeyboard(int keyNumber, int width, int height, const string color) {
            keyboard.setKeyboard(keyNumber, width, height, color);
        }

        MainKeyboard &getKeyboard() {
            return keyboard;
        }

        void setScreen(MainScreen::ScreenType type,
            int width,
            int height,
            int color,
            int resolutionX,
            int resolutionY) {
            screen.setScreen(type,
                width,
                height,
                color,
                resolutionX,
                resolutionY);
        }

        MainScreen &getScreen() {
            return screen;
        }

        void setChip(MainChip::ChipType type, int width, int height, int speed) {
            chip.setChip(type,width,height,speed);
        }

        MainChip &getChip() {
            return chip;
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
        MainChip chip;
        MainKeyboard keyboard;
        MainScreen screen;

        // Different trace
        void trace_0_update() {
        }
        void trace_1_update() {
        }
        void trace_2_update() {
        }
        void trace_3_update() {
        }
        void trace_4_update() {
        }
        void trace_5_update() {
        }
        void trace_6_update() {
        }
    };
}