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
            position = SDL_GetTicks() % 32000;
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

        bool isConnected() {
            return this->connected;
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
            chip.setChip(type, width, height, speed);
        }

        MainChip &getChip() {
            return chip;
        }

        int getX() const {
            return x;
        }

        int getY() const {
            return y;
        }

    protected:
        MainMobileClient(MainMobileClientType cliType, int ID, int x, int y)
            :clientType(cliType), id(ID), x0(x), y0(y) {
            trace = (id - 1) % 7;
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
        bool connected;
        const int x0, y0;
        int range;
        MainChip chip;
        MainKeyboard keyboard;
        MainScreen screen;


        // Different trace
        const double PI = 3.1415926;
        int position = 0;
        void trace_0_update() {
            if (position < 8000 * velocity) {
                x = SDL_static_cast(int, x0 + range * 100.0 * position / 8000 / velocity);
                y = y0;

            } else if (position < 16000 * velocity) {
                x = x0 + range * 100;
                y = SDL_static_cast(int, y0 + range * 100.0 * (position % 8000 ) / 8000 / velocity);

            } else if (position < 24000 * velocity) {
                x = SDL_static_cast(int, x0 + range * 100.0 * (8000- position % 8000 ) / 8000 / velocity);
                y = y0 + range * 100;

            } else {
                x = x0;
                y = SDL_static_cast(int, y0 + range * 100.0 * ( 8000 - position % 8000 ) / 8000 / velocity);

            }
        }
        void trace_1_update() {
            x = SDL_static_cast(int, x0 + range * 25 * SDL_sin(velocity * PI *position / 8000));
            y = SDL_static_cast(int, y0 + range * 25 * SDL_cos(velocity * PI *position / 8000));
        }
        void trace_2_update() {
            x = SDL_static_cast(int, x0 + range * 25 * SDL_sin(velocity * PI *position / 8000));
            y = SDL_static_cast(int, y0 + range * 25 * SDL_cos(velocity * PI *position / 8000));
        }
        void trace_3_update() {
            x = SDL_static_cast(int, x0 + range * 25 * SDL_sin(velocity * PI *position / 8000));
            y = SDL_static_cast(int, y0 + range * 25 * SDL_cos(velocity * PI *position / 8000));
        }
        void trace_4_update() {
            x = SDL_static_cast(int, x0 + range * 25 * SDL_sin(velocity * PI *position / 8000));
            y = SDL_static_cast(int, y0 + range * 25 * SDL_cos(velocity * PI *position / 8000));
        }
        void trace_5_update() {
            x = SDL_static_cast(int, x0 + range * 25 * SDL_cos(velocity * PI *position / 8000));
            y = SDL_static_cast(int, y0 + range * 25 * SDL_sin(velocity * PI *position / 8000));
        }
        void trace_6_update() {
            x = SDL_static_cast(int, x0 + range * 25 * SDL_cos(velocity * PI *position / 8000));
            y = SDL_static_cast(int, y0 + range * 25 * SDL_sin(velocity * PI *position / 8000));
        }
    };
}