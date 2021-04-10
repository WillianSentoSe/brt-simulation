#ifndef CAR_HPP
#define CAR_HPP

#include <string>
#include "./automata.hpp"
#include "./configuration.hpp"

class Automata;

class Car {
public:
    /* Public Variables */
    int id, speed, size, x, y;

    /* Constructor */
    Car(int id, Configuration _config);

    /* Static Methods */
    static Car *createArrayOfCars(int, Configuration);

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