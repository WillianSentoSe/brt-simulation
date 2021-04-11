#include "../../headers/car.hpp"

Car::Car(int _id, int _initiaSpeed, Station* _stations) {
    id = _id;
    x = 0;
    lane = MAIN_LANE;
    speed = _initiaSpeed;
    nextStation = 0;
    status = DRIVING;
    sleepingTime = 0;
    wantChangeLane = false;
}

Car::Car() {}

std::list<Car> Car::createListOfCars() {
    std::list<Car> newList(0);
    return newList;
}

void Car::move(int **_road, int _roadLenght, int _maxSpeed, float _breakProbability, Station* _stations, int _stationCount) {

    if (status == DRIVING) {

        // Atualizando velocidade e posição do carro
        speed = getNewSpeed(_road, _roadLenght, _maxSpeed, _breakProbability, _stations);
        x += speed;

        // Verificando se carro chegou em uma estação
        if (nextStation != UNDEFINED && x == _stations[nextStation].x) {
            status = STOPPED;
            sleepingTime = 5;
        }
    }

    if (status == STOPPED) {

        // Se ainda falta tempo parado
        if (sleepingTime > 1) {
            sleepingTime--;
        }

        // Se o tempo parado terminou
        else {
            status = DRIVING;
            nextStation = getNextStation(_stations, _stationCount);
        }
    }

}

int Car::getNewSpeed(int **_road, int _roadLenght, int _maxSpeed, float _breakProbability, Station* _stations) {
    int newSpeed = speed;
    bool canSpeedUp = true;

    if (wantChangeLane) return 0;

    for (int i = 1; i <= speed; i++) {

        // Verificando se a posição passou do limite da pista
        if(x + i > _roadLenght - 1){
            status = REMOVED;
            canSpeedUp = false;
            break;
        }
        
        // Verificando há carros na posição
        else if (_road[x + i][lane] != ROAD) {
            newSpeed = i - 1;
            canSpeedUp = false;
            break;
        }
        
        // Verificando se a posição é a próxima parada
        else if (nextStation != UNDEFINED && x + i == _stations[nextStation].x) {
            newSpeed = i;
            canSpeedUp = false;
            break;
        }
    }

    // Aumentando velocidade quando possível
    if (canSpeedUp && newSpeed < _maxSpeed && _road[x + 1][lane] == ROAD) {
        newSpeed++;
    }
    
    // Desacelerando aleatoriamente
    if(newSpeed > 0 && randomSlowDown(_breakProbability)){
        newSpeed--;
    }

    return newSpeed > 0? newSpeed : 0;
}

void Car::switchLane(int **_road, int _roadLenght, Station* _stations) {

    bool hasNextStation = nextStation != UNDEFINED;
    int closeToStation = false;

    if (nextStation != UNDEFINED) {
        closeToStation = getDistance(x, _stations[nextStation].x) <= _stations[nextStation].size;
    }

    // Verificando se carro quer parar na estação
    if (lane == MAIN_LANE && closeToStation){
        wantChangeLane = true;

        // Verificando se carro pode parar na estação
        if (_road[x][STATION_LANE] == ROAD) {
            lane = STATION_LANE;
            wantChangeLane = false;
        }
    }

    // Verificando se carro quer sair da estação
    else if (lane == STATION_LANE && !closeToStation && status == DRIVING) {

        // Verificando se carro pode sair da estação
        if (_road[x][MAIN_LANE] == ROAD) {
            lane = MAIN_LANE;
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
    result.append("] = { POSITION = (");
    result.append(std::to_string(x));
    result.append(", ");
    result.append(std::to_string(lane));
    result.append(") | VELOCITY = (");
    result.append(std::to_string(speed));
    result.append(") | STATUS = (");
    result.append(parseStatus(status));
    result.append(") }");

    return result;
} 