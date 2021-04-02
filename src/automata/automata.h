class Automata {

    public:
    int roadLength;
    bool* road;
    int carCount;
    Car* cars;
    int maxSpeed;

    // == CONSTRUTORES == //

    Automata(Configuration _config) {
        roadLength = _config.roadLength;
        road = new bool[roadLength];
        carCount = _config.carCount;
        cars = Car::createArrayOfCars(carCount, _config);
    }

    // == MÉTODOS PÚBLICOS == //

    bool checkPosition(int _x, int _y) {
        return road[_x];
    }

    // == MÉTODOS AUXILIARES == //

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
};