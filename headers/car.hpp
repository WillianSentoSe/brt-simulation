#ifndef CAR_HPP
#define CAR_HPP

class Car {
public:

    /* Public Variables */
    int id = UNDEFINED, speed = UNDEFINED, size = UNDEFINED, x = UNDEFINED, lane = UNDEFINED, status = UNDEFINED;
    int nextStation = 0, sleepingTime = 0;
    bool wantChangeLane = false;

    /* Constructor */
    Car(int _id, int _initiaSpeed, Station* _stations);
    Car();

    /* Static Methods */
    static std::list<Car> createListOfCars();

    /* Public Methods */
    void move(int **_road, Configuration* conf, Station* _stations);
    void switchLane(int **_road, int _roadLenght, Station* _stations);

    /* Utils */
    std::string toString();

private:
    /* Private Methods */
    int getNewSpeed(int **_road, Configuration* conf, Station* _stations);
    int getNextStation(Station* _stations, int _stationCount);
};

#endif // CAR_HPP