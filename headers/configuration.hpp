#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

class Configuration {

    public: 
    int initialCarSpeed = 1;
    int defaultCarSize = 2;
    int roadLength = 100;
    int maxCarCount = 25;
    int maxSpeed = 3;
    int totalIterations = 1000;
    int newCarIntervalMin = 1;
    int newCarIntervalMax = 4;
    int stationsCount = 3;

    float breakProbability = 0.45;

    /* Constructor */
    Configuration(int argc, char **argv);
    Configuration();

    std::string toString();
};

#endif // CONFIGURATION_HPP