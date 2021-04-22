#include "../../headers/automata.hpp"

Automata::Automata(Configuration *_config) {
    config    = _config;
    road      = createIntegerMatrix(config->roadLength);
    cars      = Car::createListOfCars();
    stations  = Station::createStationsList(config->stationsCount, config->roadLength);

    if (config->numThreads > 1) {
        omp_set_num_threads(config->numThreads);
    }
}

// == MÉTODOS PÚBLICOS == //

void Automata::startSimulation() {
    int currentIteration = 0;

    while(currentIteration++ < config->totalIterations) {
        updateCarList();
        iterationStep();
        //printRoad(currentIteration);
    }
}

void Automata::iterationStep() {

    int **newRoad = createRoad();

    // Verificando mudança de faixa (🙏🏼 PARALELIZAVEL 🙏🏼)
    #pragma omp parallel
    for (std::list<Car>::iterator car = cars.begin(); car != cars.end(); car++){

        #pragma omp single nowait
        if(car->status == DRIVING) {
            car->switchLane(road, config->roadLength, stations);
        }
    }

    // Movendo todos os carros (🙏🏼 PARALELIZAVEL 🙏🏼)
    #pragma omp parallel
    for (std::list<Car>::iterator car = cars.begin(); car != cars.end(); car++){
        
        #pragma omp single nowait
        {
            car->move(road, config, stations);
            
            if (car->x < config->roadLength)
                newRoad[car->x][car->lane] = OCCUPIED;
        } 
        
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

    // Percorrendo a lista de carros e removendo elementos inativos
    while (car != cars.end()) {
        if (car->status == REMOVED) {
            car = cars.erase(car);
        }
        else {
            ++car;
        }
    }

    // Adicionando novos carros periodicamente
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