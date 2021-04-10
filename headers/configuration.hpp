#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <iostream>

class Configuration {

    public: 
    int initialCarSpeed = 4;
    int defaultCarSize = 2;
    int roadLength = 100;
    int carCount = 25;
    int maxSpeed = 5;
    int totalIterations = 1000;

    /* Constructor */
    Configuration(int argc, char **argv);
};

#endif // CONFIGURATION_HPP