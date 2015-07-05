#pragma once
#include "Include.h"
namespace CellularNetworkDemonstration {
    class MainChip {
    public:
        const static int INFO_UNKNOWN = -1;
        enum ChipType {
            CHIP_TYPE_X86,
            CHIP_TYPE_AMD64,
            CHIP_TYPE_IA64,
            CHIP_TYPE_ARM,
            CHIP_TYPE_POWER_PC
        };
        MainChip(ChipType type = CHIP_TYPE_AMD64,
            int width = INFO_UNKNOWN,
            int height = INFO_UNKNOWN,
            double speed = INFO_UNKNOWN) {
            this->type = type;
            this->width = width;
            this->height = height;
            this->speed = speed;
        }
        ~MainChip() {
        }
        void setChip(ChipType type, int width, int height, int speed) {
            this->type = type;
            this->width = width;
            this->height = height;
            this->speed = speed;
        }
        void setType(ChipType type) {
            this->type = type;
        }
        ChipType getType() const {
            return this->type;
        }
        string getTypeName() const {
            switch (type) {
                case CellularNetworkDemonstration::MainChip::CHIP_TYPE_X86:
                    return "x86";
                    break;
                case CellularNetworkDemonstration::MainChip::CHIP_TYPE_AMD64:
                    return "AMD-64";
                    break;
                case CellularNetworkDemonstration::MainChip::CHIP_TYPE_IA64:
                    return "IA-64";
                    break;
                case CellularNetworkDemonstration::MainChip::CHIP_TYPE_ARM:
                    return "ARM";
                    break;
                case CellularNetworkDemonstration::MainChip::CHIP_TYPE_POWER_PC:
                    return "Power PC";
                    break;
                default:
                    return "";
                    break;
            }
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
        void setSpeed(double speed) {
            this->speed = speed;
        }
        double getSpeed() const {
            return this->speed;
        }
    private:
        ChipType type;
        int width;
        int height;
        double speed;
    };
}