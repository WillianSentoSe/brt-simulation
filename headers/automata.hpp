#ifndef AUTOMATA_HPP
#define AUTOMATA_HPP

class Automata {

public:
    /* Public Variables */
    int carCount, maxSpeed, roadLength, totalIterations;
    bool* road;
    std::list<Car> cars;

    /* Constructor */
    Automata(Configuration _config);

    /* Public Methods */
    void startSimulation();
    bool checkPosition(int _x, int _y);
    bool* createRoad(int _length);

    /* Utils */
    std::string toString();

private:
    /* Private Methods */
    void iterationStep();
    void printRoad(int iteration);
};

#endif // AUTOMATA_HPP