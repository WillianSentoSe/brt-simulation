#ifndef AUTOMATA_HPP
#define AUTOMATA_HPP

class Automata {

public:
    /* Public Variables */
    Configuration *config;
    int** road;
    Station* stations;
    std::list<Car> cars;

    /* Constructor */
    Automata(Configuration *_config);

    /* Public Methods */
    void startSimulation();
    int** createRoad();

    /* Utils */
    std::string toString();

private:
    /* Private Variables */
    int nextCarIn = 0;

    /* Private Methods */
    void iterationStep();
    void printRoad(int iteration);
    void updateCarList();
    void spawnCar();
    void createStationsList();
};

#endif // AUTOMATA_HPP