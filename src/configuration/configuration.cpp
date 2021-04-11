#include "../../headers/configuration.hpp"

Configuration::Configuration(int argc, char **argv) {
    if (argc >= 2) totalIterations = std::stoi(argv[1]);
    if (argc >= 3) roadLength = std::stoi(argv[2]);
    if (argc >= 4) carCount = std::stoi(argv[3]);
    if (argc >= 5) maxSpeed = std::stoi(argv[4]);
    if (argc >= 6) newCarIntervalMin = std::stoi(argv[5]);
    if (argc >= 7) newCarIntervalMax = std::stoi(argv[6]);
    if (argc >= 8) breakProbability = std::stoi(argv[7]);
}