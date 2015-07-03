#pragma once
#include "Include.h"
namespace CellularNetworkDemonstration {
    class MainKeyboard {
    public:
        const static int INFO_UNKNOWN = -1;
        MainKeyboard(
            int keyNumber = 103,
            int width = INFO_UNKNOWN,
            int height = INFO_UNKNOWN,
            const SDL_Color &color = SDL_Color{ 0,0,0,0}) {
            this->keyNumber = keyNumber;
            this->width = width;
            this->height = height;
            this->color = color;
        }
        ~MainKeyboard() {
        }
        void setKeyNumber(int keyNumber) {
            this->keyNumber = keyNumber;
        }
        int getKeyNumber() const {
            return this->keyNumber;
        }
        void setWidth(int width) {
            this->width = width;
        }
        int getWidth() const {
            return this->width;
        }
        void setHeight(int height) {
            this->height = height;
        }
        int getHeight() const {
            return this->height;
        }
        void setColor(SDL_Color& color) {
            this->color = color;
        }
        SDL_Color getColor() const {
            return this->color;
        }
    private:
        int keyNumber;
        int width;
        int height;
        SDL_Color color;
    };
}