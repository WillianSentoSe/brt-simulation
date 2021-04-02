class Automata {

    public:
    int roadLength;
    int totalIterations;
    bool* road;
    int carCount;
    Car* cars;
    int maxSpeed;

    public:

    // == CONSTRUTORES == //

    Automata(Configuration _config) {
        roadLength = _config.roadLength;
        road = new bool[roadLength];
        carCount = _config.carCount;
        cars = Car::createArrayOfCars(carCount, _config);
        totalIterations = _config.totalIterations;
    }

    // == MÉTODOS PÚBLICOS == //

    bool checkPosition(int _x, int _y) {
        return road[_x];
    }

    void startSimulation() {
        int currentIteration = 0;

        while(currentIteration++ < totalIterations) {
            iterationStep();
            printRoad(currentIteration);
        }
    }

    std::string toString() {
        std::string result;

        result.append("[");

        for (int i = 0; i < roadLength; i++) {
            bool occupied = checkPosition(i, 0);
            result.append(occupied? "1" : "0");
            result.append(i < roadLength - 1? " " : "");
        }

        result.append("]");

        return result;
    }

    private:
    
    // == MÉTODOS PRIVADOS == //

    void iterationStep() {

    }

    void printRoad(int iteration) {
        std::cout << "(" << iteration << ")\t" << toString() << std::endl;
    }

};