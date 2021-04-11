#include "../../headers/automata.hpp"

Automata::Automata(Configuration *_config) {
    config    = _config;
    road      = createBooleanMatrix(config->roadLength);
    cars      = Car::createListOfCars();
    stations  = Station::createStationsList(config->stationsCount);
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

bool Automata::checkPosition(int _x, int _y) {
    return road[_x];
    //TODO: Verificar Y
}

bool* Automata::createRoad(int _length) {
    bool *road = (bool*) malloc(sizeof(bool) * _length);

    for (int i = 0; i < _length; i++) {
        road[i] = false;
    }

    return road;
}

std::string Automata::toString() {
    std::string result;

    result.append("|");

    // Imprimindo faixa secundária
    for (int i = 0; i < config->roadLength; i++) {
        bool occupied = road[i][1];
        result.append(occupied? "O" : " ");
        result.append(i < config->roadLength - 1? " " : "");
    }

    result.append("|\n\t|");

    // Imprimindo faixa principal
    for (int i = 0; i < config->roadLength; i++) {
        bool occupied = road[i][0];
        result.append(occupied? "O" : "_");
        result.append(i < config->roadLength - 1? " " : "");
    }

    result.append("|\n");

    return result;
}

// == MÉTODOS PRIVADOS == //

void Automata::iterationStep() {

    bool **newRoad = createBooleanMatrix(config->roadLength);
    std::list<Car>::iterator car = cars.begin();

    // Verificando mudança de faixa
    // TODO: percorrer todos os carros e efetuar mudança de faixa

    // Movendo todos os carros
    while (car != cars.end()) {
        if(car->active) {
            car->move(newRoad);
            // print(car->toString());
        }
        car++;
    }

    road = newRoad;
}

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
        Car newCar(cars.size(), config);
        cars.insert(cars.end(), newCar);
        nextCarIn = getRandomInt(config->newCarIntervalMin, config->newCarIntervalMax);
    }
}