#include <iostream>
#include "header.h"
#include "./configuration/configuration.h"
#include "./car/car.h"
#include "./automata/automata.h"

int main() {
    Configuration initialConfig;
    Automata automata(initialConfig);

    std::cout << automata.toString() << std::endl;
    std::cout << automata.carCount << std::endl;
    
    return 0;
}