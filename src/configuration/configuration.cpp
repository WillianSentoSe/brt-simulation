#include "../../headers/configuration.hpp"

Configuration::Configuration(int argc, char **argv) {
    if (argc >= 2) totalIterations = std::stoi(argv[1]);
    if (argc >= 3) roadLength = std::stoi(argv[2]);
    if (argc >= 4) carCount = std::stoi(argv[3]);
}