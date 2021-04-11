int getRandomInt(int min, int max) {
    return rand() % (max-min + 1) + min;
}

bool* createBooleanArray(int _size) {
    bool *newArray = new bool[_size];

    for (int i = 0; i < _size; i++) {
        newArray[i] = false;
    }

    return newArray;
}

bool** createBooleanMatrix(int _size) {
    bool** newMatrix = new bool*[_size];

    for (int i = 0; i < _size; i++) {
        newMatrix[i] = new bool[2] { false, false };
    }

    return newMatrix;
}

void print(std::string str) {
    std::cout << str << std::endl;
}