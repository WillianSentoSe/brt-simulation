#ifndef CAR_HPP
#define CAR_HPP

class Car {
public:

    /* Public Variables */
    int id, speed, size, x, y;
    bool active = false;

    /* Constructor */
    Car(int _id, int _initiaSpeed);
    Car();

    /* Static Methods */
    static std::list<Car> createListOfCars();

    /* Public Methods */
    void move(bool **_road, int _roadLenght, int _maxSpeed, float _breakProbability);

    /* Utils */
    std::string toString();

private:
    /* Private Methods */
    bool randomSlowDown(float _breakProbability);
    int getNewSpeed(bool **_road, int _roadLenght, int _maxSpeed, float _breakProbability);
};

#endif // CAR_HPP