#include <iostream>
#include "header.h"
#include "./configuration/configuration.h"
#include "./car/car.h"
#include "./automata/automata.h"

int main(int argc, char **argv) {

    Configuration initialConfig(argc, argv);
    Automata automata(initialConfig);

    automata.startSimulation();
    
    return 0;
}