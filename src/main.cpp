#include <iostream>
#include "header.hpp"
#include "./configuration/configuration.cpp"
#include "./automata/automata.cpp"
#include "./car/car.cpp"

int main(int argc, char **argv) {

    Configuration initialConfig(argc, argv);
    Automata automata(initialConfig);

    automata.startSimulation();
    
    return 0;
}