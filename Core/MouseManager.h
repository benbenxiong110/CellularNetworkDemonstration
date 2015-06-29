#pragma once
#include <SDL.h>
namespace CellularNetworkDemonstration {
    class MouseManager {
    public:
        ~MouseManager() {
        }
        static MouseManager& get() {
            static MouseManager* m_pManager;
            if (!m_pManager) {
                m_pManager = new MouseManager();
            }
            return *m_pManager;
        }

        void OnMouseButtonUp(const SDL_Event &event) {

            switch (event.button.button) {
                case SDL_BUTTON_LEFT:
                    leftButtonDown = false;
                    break;
                case SDL_BUTTON_MIDDLE:
                    middleButtonDown = false;
                    break;
                case SDL_BUTTON_RIGHT:
                    rightButtonDown = false;
                    break;
                default:
                    break;
            }
        }

        void OnMouseButtonDown(const SDL_Event &event) {
            switch (event.button.button) {
                case SDL_BUTTON_LEFT:
                    leftButtonDown = true;
                    break;
                case SDL_BUTTON_MIDDLE:
                    middleButtonDown = true;
                    break;
                case SDL_BUTTON_RIGHT:
                    rightButtonDown = true;
                    break;
                default:
                    break;
            }
        }

        void OnMouseMotion(const SDL_Event &event) {
            x = event.motion.x;
            y = event.motion.y;
        }
        void OnMouseWheel(const SDL_Event &event) {
            //event.wheel.
        }

        bool checkMousePos(const SDL_Rect* rect) {
            return x >= rect->x
                &&y >= rect->y
                &&x <= rect->x + rect->w
                &&y <= rect->y + rect->h;
        }

        int getX() const {
            return x;
        }
        int getY() const {
            return y;
        }
    private:
        MouseManager() {
        }
        int x, y;
        int xRel, yRel;
        bool leftButtonDown;
        bool middleButtonDown;
        bool rightButtonDown;

    };


}


