#include "../../headers/car.hpp"

Car::Car(int _id, int _initiaSpeed, Station* _stations) {
    id = _id;
    x = 0;
    y = 0;
    active = true;
    speed = _initiaSpeed;
    nextStation = 0;
    wantChangeLane = false;
}

Car::Car() {}

std::list<Car> Car::createListOfCars() {
    std::list<Car> newList(0);
    return newList;
}

void Car::move(int **_road, int _roadLenght, int _maxSpeed, float _breakProbability, Station* _stations, int _stationCount) {
    speed = getNewSpeed(_road, _roadLenght, _maxSpeed, _breakProbability, _stations);
    x += speed;

    if (x == _stations[nextStation].x) {
        sleeping = 5;
        nextStation = getNextStation(_stations, _stationCount);
    }
}

int Car::getNewSpeed(int **_road, int _roadLenght, int _maxSpeed, float _breakProbability, Station* _stations) {
    int newSpeed = speed;
    bool canSpeedUp = true;

    if (wantChangeLane) return 0;

    for (int i = 1; i <= speed; i++) {

        // Verificando se a posição passou do limite da pista
        if(x + i > _roadLenght - 1){
            active = false;
            canSpeedUp = false;
            break;
        }
        
        // Verificando há carros na posição
        else if (_road[x + i][y] != ROAD) {
            newSpeed = i - 1;
            canSpeedUp = false;
            break;
        }
        
        // Verificando se a posição é a próxima parada
        else if (x + i == _stations[nextStation].x) {
            newSpeed = i;
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

void Car::switchLane(int **_road, int _roadLenght, Station* _stations) {
    if (nextStation == UNDEFINED) return;

    Station station = _stations[nextStation];

    // Verificando se carro quer parar na estação
    if (y == 0 && x >= station.x - station.size){
        wantChangeLane = true;

        // Verificando se carro pode parar na estação
        if (_road[x][1] != OCCUPIED) {
            y = 1;
            wantChangeLane = false;
        }
    }

    // Verificando se carro quer sair da estação
    else if (y == 1 && x < station.x - station.size) {

        // Verificando se carro pode sair da estação
        if (_road[x][0] != OCCUPIED) {
            y = 0;
        }
    }
}

int Car::getNextStation(Station* _stations, int _stationCount) {
    int _nextStation = nextStation < _stationCount? nextStation + 1 : UNDEFINED;
    return _nextStation;
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