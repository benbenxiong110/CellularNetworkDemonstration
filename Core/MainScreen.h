#pragma once
#include "Include.h"
namespace CellularNetworkDemonstration {
    class MainScreen {
    public:
        const static int INFO_UNKNOWN = -1;
        enum ScreenType {
            SCREEN_TYPE_NO_TOUCH,
            SCREEN_R_TOUCH,
            SCREEN_C_TOUCH,
            SCREEN_MULTI_C_TOUCH
        };
        MainScreen(ScreenType type = SCREEN_TYPE_NO_TOUCH,
            int width = INFO_UNKNOWN,
            int height = INFO_UNKNOWN,
            int color = INFO_UNKNOWN,
            int resolutionX = INFO_UNKNOWN,
            int resolutionY = INFO_UNKNOWN) {
            this->type = type;
            this->width = width;
            this->height = height;
            this->color = color;
            this->resolutionX = resolutionX;
            this->resolutionY = resolutionY;
        }
        ~MainScreen() {
        }

        void setScreen(ScreenType type,
            int width,
            int height,
            int color,
            int resolutionX,
            int resolutionY) {
            this->type = type;
            this->width = width;
            this->height = height;
            this->color = color;
            this->resolutionX = resolutionX;
            this->resolutionY = resolutionY;
        }

        void setType(ScreenType type) {
            this->type = type;
        }
        ScreenType getType() const {
            return this->type;
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
        void setColor(int color) {
            this->color = color;
        }
        int getColor() const {
            return this->color;
        }
        void setResolution(int x, int y) {
            this->resolutionX = x;
            this->resolutionY = y;
        }
        void setResolutionX(int resolutionX) {
            this->resolutionX = resolutionX;
        }
        int getResolutionX() const {
            return this->resolutionX;
        }
        void setResolutionY(int resolutionY) {
            this->resolutionY = resolutionY;
        }
        int getResolutionY() const {
            return this->resolutionY;
        }
    private:
        ScreenType type;
        int width;
        int height;
        int color;
        int resolutionX;
        int resolutionY;
    };
}