#include <iostream>
#include "header.h"
#include "./car/car.h"

int main() {
    Configuration initialConfig;
    Car carro1(initialConfig);

    std::cout << carro1.toString() << std::endl;
    
    return 0;
}