#include <iostream>
#include "header.h"
#include "./configuration/configuration.h"
#include "./car/car.h"
#include "./automata/automata.h"

int main(int argc, char **argv) {

    Configuration initialConfig(argc, argv);
    Automata automata(initialConfig);

    std::cout << automata.toString() << std::endl;
    std::cout << automata.carCount << std::endl;
    
    return 0;
}