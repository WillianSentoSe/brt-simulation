#ifndef CAR_HPP
#define CAR_HPP

class Car {
public:

    /* Public Variables */
    Configuration *config;
    int id, speed, size, x, y;
    bool active = false;

    /* Constructor */
    Car(int id, Configuration *_config);
    Car();

    /* Static Methods */
    static std::list<Car> createListOfCars();

    /* Public Methods */
    void move(bool **road);

    /* Utils */
    std::string toString();

private:
    /* Private Methods */
    bool randomSlowDown();
    int getNewSpeed(bool **road);
    int updateSpeed(bool **road);
};

#endif // CAR_HPP