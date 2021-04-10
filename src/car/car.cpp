#include "../../headers/car.hpp"

Car::Car(int _id, Configuration _config) {
    speed = _config.initialCarSpeed;
    size = _config.defaultCarSize;
    id = _id;
    x = UNDEFINED;
    y = UNDEFINED;
    active = true;
}

Car::Car() {
    // Empty Constructor
}

/***
 * MÉTODOS ESTÁTICOS
 ***/

std::list<Car> Car::createListOfCars(int _size, Configuration _config) {
    std::list<Car> newList(0);
    std::list<Car>::iterator it;

    for(int i = 0; i < _size; i++) {
        Car newCar(0, _config);
        newList.insert(it, newCar);
    }

    return newList;
}

int Car::getNewSpeed(Automata _automata) {
    for (int i = x; i < x + speed; i++) {

        if(i + speed > _automata.roadLength){
            active = false;
            return speed;
        }
        if (_automata.checkPosition(i, y)) {
            return speed = i - 1;
        }
    }

    if(randomSlowDown()){
        return speed -= 1;
    }
    
    return speed < _automata.maxSpeed ? speed + 1 : speed;
}

// Gera números entre 0 e 1, caso maior que 0.25, desacelera
bool Car::randomSlowDown(){
    return (double)rand() / ((double)RAND_MAX + 1) <= 0.25;
}

void Car::move(Automata _automata) {
    speed = getNewSpeed(_automata);
    x += speed;
}

// 0 0 0 0 0 0 0 4 0 1 0 0 0 0 

/* == MÉTODOS PUBLICOS == */

std::string Car::toString() {
    std::string result;

    result.append("Car [");
    result.append(std::to_string(id));
    result.append("] = { POS = (");
    result.append(std::to_string(x));
    result.append(", ");
    result.append(std::to_string(y));
    result.append(") | VEL = (");
    result.append(std::to_string(speed));
    result.append(") }");

    return result;
} 

