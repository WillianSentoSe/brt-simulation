#include <iostream>
#include "header.hpp"
#include "./configuration/configuration.cpp"
#include "./automata/automata.cpp"
#include "./car/car.cpp"
#include<time.h>

int main(int argc, char **argv) {

    Configuration initialConfig(argc, argv);
    Automata automata(initialConfig);
    srand((unsigned) time(0));

    automata.startSimulation();
    
    return 0;
}