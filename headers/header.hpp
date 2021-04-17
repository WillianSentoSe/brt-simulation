#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <time.h>
#include <string>
#include <list>
#include <omp.h>

#define UNDEFINED -1

// TIPOS DE CÉLULAS
#define WALL -1
#define ROAD 0
#define OCCUPIED 1

// STATUS DOS CARROS
#define REMOVED -1
#define STOPPED 0
#define DRIVING 1

// TIPOS DE FAIXA
#define MAIN_LANE 0
#define STATION_LANE 1

// TIPOS DE FAIXA
#define SEQUENTIAL_FLG 0
#define PARALLEL_FLG 1

class Station;
class Automata;
class Configuration;
class Car;

#include "./configuration.hpp"
#include "./car.hpp"
#include "./station.hpp"
#include "./automata.hpp"

#include "../src/util/util.cpp"
#include "../src/configuration/configuration.cpp"
#include "../src/car/car.cpp"
#include "../src/station/station.cpp"
#include "../src/automata/automata.cpp"

#endif // MAIN_HPP
