#include "../../headers/car.hpp"

Car::Car(int _id, Configuration *_config) {
    config = _config;
    id = _id;
    x = 0;
    y = 0;
    active = true;
    speed = _config->initialCarSpeed;
}

Car::Car() {
    // Empty Constructor
}

std::list<Car> Car::createListOfCars(int _size, Configuration *_config) {
    std::list<Car> newList(0);

    for(int i = 0; i < _size; i++) {
        Car newCar(i, _config);
        newList.insert(newList.end(), newCar);
    }

    return newList;
}

int Car::getNewSpeed(bool *_road) {
    int newSpeed = speed;
    bool canSpeedUp = true;

    for (int i = 0; i <= speed; i++) {

        // Verificando se a posição passou do limite da pista
        if(x + i > config->roadLength - 1){
            active = false;
            canSpeedUp = false;
            break;
        }
        
        // Verificando há carros na posição
        else if (_road[x + i]) {
            newSpeed = i - 1;
            canSpeedUp = false;
            break;
        }
        
    }

    // Aumentando velocidade quando possível
    if (canSpeedUp && newSpeed < config->maxSpeed) {
        newSpeed++;
    }
    
    // Desacelerando aleatoriamente
    if(newSpeed > 0 && randomSlowDown()){
        newSpeed--;
    }

    return newSpeed;
}

// Gera números entre 0 e 1, caso maior que breakProbability, desacelera
bool Car::randomSlowDown(){
    return (double)rand() / ((double)RAND_MAX + 1) <= config->breakProbability;
}

void Car::move(bool *_road) {
    speed = getNewSpeed(_road);

    x += speed;
    if (x < config->roadLength) {
        _road[x] = true;
    }
}

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
    result.append(") | ATV = (");
    result.append(active? "TRUE" : "FALSE");
    result.append(") }");

    return result;
} 

