#include "../../headers/automata.hpp"

Automata::Automata(Configuration *_config) {
    config    = _config;
    road      = createIntegerMatrix(config->roadLength);
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

    int **newRoad = createRoad();
    std::list<Car>::iterator car = cars.begin();

    // Verificando mudança de faixa (🙏🏼 PARALELIZAVEL 🙏🏼)
    while (car != cars.end()) {
        if(car->status == DRIVING) {
            car->switchLane(road, config->roadLength, stations);
        }
        car++;
    }

    car = cars.begin();

    // Movendo todos os carros (🙏🏼 PARALELIZAVEL 🙏🏼)
    while (car != cars.end()) {
        car->move(road, config->roadLength, config->maxSpeed, config->breakProbability, stations, config->stationsCount);
        
        if (car->x < config->roadLength)
            newRoad[car->x][car->lane] = OCCUPIED;
        
        car++;
    }

    road = newRoad;
}

int** Automata::createRoad() {
    int **road = createIntegerMatrix(config->roadLength);

    for (int i = 0; i < config->stationsCount; i++) {
        Station station = stations[i];
        
        for (int j = 0; j < station.size * 2 + 1; j++) {
            int pos = station.x - station.size + j;

            if (pos >= 0 && pos < config->roadLength - 1) {
                road[pos][1] = ROAD;
            }
        }
    }

    return road;
}


std::string Automata::toString() {
    std::string secundaryRoad = "";
    std::string primaryRoad = "";
    std::string result = "";

    for (int i = 0; i < config->roadLength; i++) {
        // Faixa primaria
        primaryRoad.append(parseCode(road[i][0]));
        primaryRoad.append(i < config->roadLength - 1? " " : "");

        // Faixa secundária
        secundaryRoad.append(parseCode(road[i][1]));
        secundaryRoad.append(i < config->roadLength - 1? " " : "");
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
        if (car->status != REMOVED) {
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
    if (road[0][0] == ROAD && cars.size() < config->maxCarCount) {
        Car newCar(cars.size(), config->initialCarSpeed, stations);
        cars.insert(cars.end(), newCar);
        nextCarIn = getRandomInt(config->newCarIntervalMin, config->newCarIntervalMax);
    }
}