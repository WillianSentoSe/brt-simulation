#define UNDEFINED -1

class Configuration;
class Automata;
class Car {
    public:
    static Car* createArrayOfCars(int, Configuration);
    int updateSpeed(Automata*);
};