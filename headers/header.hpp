#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <time.h>
#include <string>
#include <list>

#define UNDEFINED -1

#define WALL -1
#define ROAD 0
#define OCCUPIED 1

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
