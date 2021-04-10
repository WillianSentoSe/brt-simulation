#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

class Configuration {

    public: 
    int initialCarSpeed = 1;
    int defaultCarSize = 2;
    int roadLength = 100;
    int carCount = 25;
    int maxSpeed = 1;
    int totalIterations = 1000;
    int newCarIntervalMin = 1;
    int newCarIntervalMax = 1;

    float breakProbability = 0.25;

    /* Constructor */
    Configuration(int argc, char **argv);
    Configuration();
};

#endif // CONFIGURATION_HPP