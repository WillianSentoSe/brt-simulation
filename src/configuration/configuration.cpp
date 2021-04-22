#include "../../headers/configuration.hpp"

Configuration::Configuration(int argc, char **argv) {
    if (argc >= 2) totalIterations = std::stoi(argv[1]);
    if (argc >= 3) roadLength = std::stoi(argv[2]);
    if (argc >= 4) maxCarCount = std::stoi(argv[3]);
    if (argc >= 5) maxSpeed = std::stoi(argv[4]);
    if (argc >= 6) newCarIntervalMin = std::stoi(argv[5]);
    if (argc >= 7) newCarIntervalMax = std::stoi(argv[6]);
    if (argc >= 8) breakProbability = std::stof(argv[7]);
    if (argc >= 9) carStopIntervalMin = std::stoi(argv[8]);
    if (argc >= 10) carStopIntervalMax = std::stoi(argv[9]);
    if (argc >= 11) numThreads = std::stoi(argv[10]);  
    
    // print(toString());
}

std::string Configuration::toString() {
    std::string result;

    result.append("CONFIGS ");
    result.append("{ ITERATIONS = (");
    result.append(std::to_string(totalIterations));
    result.append(") | ROAD_LENGHT = (");
    result.append(std::to_string(roadLength));
    result.append(") | MAX_CARS_QNT = (");
    result.append(std::to_string(maxCarCount));
    result.append(") | MAX_SPEED = (");
    result.append(std::to_string(maxSpeed));
    result.append(") | CAR_SPWN_MIN = (");
    result.append(std::to_string(newCarIntervalMin));
    result.append(") | CAR_SPWN_MAX = (");
    result.append(std::to_string(newCarIntervalMax));
    result.append(") | BREAK_PROB = (");
    result.append(std::to_string(breakProbability));
    result.append(") | CAR_STOP_MIN = (");
    result.append(std::to_string(carStopIntervalMin));
    result.append(") | CAR_STOP_MAX = (");
    result.append(std::to_string(carStopIntervalMax));
    result.append(") | NUM_THREADS = (");
    result.append(std::to_string(numThreads));
    result.append(") }");

    return result;
} 