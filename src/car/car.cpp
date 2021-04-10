#include "../../headers/car.hpp"

Car::Car(int id, Configuration _config) {
    speed = _config.initialCarSpeed;
    size = _config.defaultCarSize;
    id = 0; // TODO: gerar novo ID 
    x = UNDEFINED;
    y = UNDEFINED;
}

/***
 * MÉTODOS ESTÁTICOS
 ***/

Car* Car::createArrayOfCars(int _size, Configuration _config) {
    Car* array = (Car*) malloc(sizeof(Car) * _size);

    for(int i = 0; i < _size; i++) {
        array[i] = Car(i, _config);
    }

    return array;
}

int Car::getNewSpeed(Automata _automata) {
    for (int i = x; i < x + speed; i++) {
        if (!(_automata.checkPosition(x, y))) {
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