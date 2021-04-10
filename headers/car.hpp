#ifndef CAR_HPP
#define CAR_HPP

class Car {
public:

    /* Public Variables */
    int id, speed, size, x, y;
    bool active = false;

    /* Constructor */
    Car(int id, Configuration _config);
    Car();

    /* Static Methods */
    static std::list<Car> createListOfCars(int, Configuration);

    /* Public Methods */
    void move(Automata _automata);

    /* Utils */
    std::string toString();

private:
    /* Private Methods */
    bool randomSlowDown();
    int getNewSpeed(Automata _automata);
    int updateSpeed(Automata *);
};

#endif // CAR_HPP