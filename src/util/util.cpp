int getRandomInt(int min, int max) {
    return rand() % (max-min + 1) + min;
}

int** createBooleanMatrix(int _size) {
    int** newMatrix = new int*[_size];

    for (int i = 0; i < _size; i++) {
        newMatrix[i] = new int[2] { OCCUPIED, WALL };
    }

    return newMatrix;
}

void print(std::string str) {
    std::cout << str << std::endl;
}

// Gera números entre 0 e 1, caso maior que breakProbability, desacelera
bool randomSlowDown(float _prob){
    return (double) rand() / ((double) RAND_MAX + 1) <= _prob;
}