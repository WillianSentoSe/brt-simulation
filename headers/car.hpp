#ifndef CAR_HPP
#define CAR_HPP

class Car {
public:

    /* Public Variables */
    int id = UNDEFINED, speed = UNDEFINED, size = UNDEFINED, x = UNDEFINED, y = UNDEFINED;
    int nextStation = 0, sleepingTime = 0;
    bool wantChangeLane = false;
    bool active = false;

    /* Constructor */
    Car(int _id, int _initiaSpeed, Station* _stations);
    Car();

    /* Static Methods */
    static std::list<Car> createListOfCars();

    /* Public Methods */
    void move(bool **_road, int _roadLenght, int _maxSpeed, float _breakProbability, Station* _stations, int _stationsCount);
    void switchLane(bool **_road, int _roadLenght, Station* _stations);

    /* Utils */
    std::string toString();

private:
    /* Private Methods */
    int getNewSpeed(bool **_road, int _roadLenght, int _maxSpeed, float _breakProbability, Station* _stations);
    int getNextStation(Station* _stations, int _stationCount);
};

#endif // CAR_HPP