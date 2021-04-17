#include "../headers/header.hpp"

int main(int argc, char **argv) {

    Configuration initialConfig(argc, argv);
    Automata automata(&initialConfig);

    srand((unsigned) time(0));

    automata.startSimulation();
    
    return 0;
}