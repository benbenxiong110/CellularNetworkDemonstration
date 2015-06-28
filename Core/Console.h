#pragma once
#include <iostream>

namespace CellularNetworkDemonstration {
    static void log(char *str) {
#ifdef DEBUG
        std::cout << str << std::endl;
#endif // DEBUG
    }

    static void log(double *num) {
#ifdef DEBUG
        std::cout << num << std::endl;
#endif // DEBUG
    }
};

