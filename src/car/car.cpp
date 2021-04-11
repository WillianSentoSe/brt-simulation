#include "../../headers/car.hpp"

Car::Car(int _id, int _initiaSpeed) {
    id = _id;
    x = 0;
    y = 0;
    active = true;
    speed = _initiaSpeed;
}

Car::Car() {}

std::list<Car> Car::createListOfCars() {
    std::list<Car> newList(0);
    return newList;
}

int Car::getNewSpeed(bool **_road, int _roadLenght, int _maxSpeed, float _breakProbability) {
    int newSpeed = speed;
    bool canSpeedUp = true;

    for (int i = 1; i <= speed; i++) {

        // Verificando se a posição passou do limite da pista
        if(x + i > _roadLenght - 1){
            active = false;
            canSpeedUp = false;
            break;
        }
        
        // Verificando há carros na posição
        else if (_road[x + i][y]) {
            newSpeed = i - 1;
            canSpeedUp = false;
            break;
        }
        
    }

    // Aumentando velocidade quando possível
    if (canSpeedUp && newSpeed < _maxSpeed) {
        newSpeed++;
    }
    
    // Desacelerando aleatoriamente
    if(newSpeed > 0 && randomSlowDown(_breakProbability)){
        newSpeed--;
    }

    return newSpeed > 0? newSpeed : 0;
}

// Gera números entre 0 e 1, caso maior que breakProbability, desacelera
bool Car::randomSlowDown(float _breakProbability){
    return (double)rand() / ((double)RAND_MAX + 1) <= _breakProbability;
}

void Car::move(bool **_road, int _roadLenght, int _maxSpeed, float _breakProbability) {
    speed = getNewSpeed(_road, _roadLenght, _maxSpeed, _breakProbability);

    x += speed;
    if (x < _roadLenght) {
        _road[x][y] = true;
    }
}

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

