class Configuration {

    public: 
    int initialCarSpeed = 4;
    int defaultCarSize = 2;
    int roadLength = 100;
    int carCount = 25;
    int maxSpeed = 5;
    int totalIterations = 1000;

    // == CONSTRUTORES == //

    Configuration(int argc, char **argv) {
        if (argc >= 2) totalIterations = std::stoi(argv[1]);
        if (argc >= 3) roadLength = std::stoi(argv[2]);
        if (argc >= 4) carCount = std::stoi(argv[3]);
    }
};