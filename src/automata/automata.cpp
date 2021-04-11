#include "../../headers/automata.hpp"

Automata::Automata(Configuration *_config) {
    config    = _config;
    road      = createBooleanMatrix(config->roadLength);
    cars      = Car::createListOfCars();
    stations  = Station::createStationsList(config->stationsCount, config->roadLength);
}

// == MÉTODOS PÚBLICOS == //

void Automata::startSimulation() {
    int currentIteration = 0;

    while(currentIteration++ < config->totalIterations) {
        updateCarList();
        iterationStep();
        printRoad(currentIteration);
    }
}

void Automata::iterationStep() {

    bool **newRoad = createRoad(config->roadLength);
    std::list<Car>::iterator car = cars.begin();

    // Verificando mudança de faixa
    while (car != cars.end()) {
        if(car->active) {
            car->switchLane(road, config->roadLength, stations);
            // print(car->toString());
        }
        car++;
    }

    car = cars.begin();

    // Movendo todos os carros
    while (car != cars.end()) {
        if(car->active) {
            if (car->sleepingTime == 0) {
                car->move(road, config->roadLength, config->maxSpeed, config->breakProbability, stations, config->stationsCount);
                
            }
            else {
                car->sleepingTime--;
            }

            if (car->x < config->roadLength) {
                newRoad[car->x][car->y] = true;
            }

            // print(car->toString());
        }
        car++;
    }

    road = newRoad;
}

bool** Automata::createRoad(int _length) {
    bool **road = createBooleanArray(config->roadLength);

    for (int i = 0; i < _length; i++) {
        road[i][0] = false;
        road[i][1] = true;
    }

    for (int i = 0; i < config->stationsCount; i++) {
    Station station = stations[i];
    
    for (int j = 0; j < (station.size * 2) + 1; j++) {
        int pos = (station.x - station.size + j) * 2;

        if (pos >= 0 && pos < _length) {
            road[i][1] = false;
        }
    }

    return road;
}

std::string Automata::toString() {
    std::string secundaryRoad = "";
    std::string primaryRoad = "";
    std::string result = "";

    // Imprimindo faixa secundária
    for (int i = 0; i < config->roadLength; i++) {
        bool occupied = road[i][1];
        secundaryRoad.append(occupied? "O" : " ");
        secundaryRoad.append(i < config->roadLength - 1? " " : "");
    }

    // Imprimindo estações
    for (int i = 0; i < config->stationsCount; i++) {
        Station station = stations[i];
        
        for (int j = 0; j < (station.size * 2) + 1; j++) {
            int pos = (station.x - station.size + j) * 2;

            if (pos >= 0 && pos < secundaryRoad.length()) {
                if (secundaryRoad.at(pos) != 'O') {
                    secundaryRoad.replace(pos, 1, "_");
                }
            }
        }
    }

    // Imprimindo faixa principal
    for (int i = 0; i < config->roadLength; i++) {
        bool occupied = road[i][0];
        primaryRoad.append(occupied? "O" : "_");
        primaryRoad.append(i < config->roadLength - 1? " " : "");
    }

    result.append("|");
    result.append(secundaryRoad);
    result.append("|\n\t|");
    result.append(primaryRoad);
    result.append("|\n");

    return result;
}

// == MÉTODOS PRIVADOS == //


void Automata::printRoad(int iteration) {
    std::cout << "(" << iteration << ")\t" << toString() << std::endl;
}

void Automata::updateCarList() {
    std::list<Car>::iterator car = cars.begin();

    // Removendo carros inativos
    while (car != cars.end()) {
        if (car->active) {
            ++car;
        }
        else {
            car = cars.erase(car);
        }
    }

    // Adicionando novos carros
    if (nextCarIn <= 0) {
        spawnCar();
    } else {
        nextCarIn--;
    }
}

void Automata::spawnCar() {
    if (road[0][0] == false && cars.size() < config->maxCarCount) {
        Car newCar(cars.size(), config->initialCarSpeed, stations);
        cars.insert(cars.end(), newCar);
        nextCarIn = getRandomInt(config->newCarIntervalMin, config->newCarIntervalMax);
    }
}