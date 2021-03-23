#include <iostream>
#include "header.h"

int main() {
    Configuration initialConfig;
    Car carro1(initialConfig);

    std::cout << carro1.toString() << std::endl;
    
    return 0;
}