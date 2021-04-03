class Automata {

    public:
    int roadLength;
    int totalIterations;
    bool* road;
    int carCount;
    Car* cars;
    int maxSpeed;

    // == CONSTRUTORES == //

    Automata(Configuration _config) {
        carCount        = _config.carCount;
        roadLength      = _config.roadLength;
        totalIterations = _config.totalIterations;
        road            = new bool[roadLength];
        cars            = Car::createArrayOfCars(carCount, _config);
    }

    // == MÉTODOS PÚBLICOS == //

    void startSimulation() {
        int currentIteration = 0;

        while(currentIteration++ < totalIterations) {
            iterationStep();
            printRoad(currentIteration);
        }
    }

    bool checkPosition(int _x, int _y) {
        return road[_x];
        //TODO: VERIFICAR Y
    }

    bool* createRoad(int _length) {
        bool *road = (bool*) malloc(sizeof(bool) * _length);

        for (int i = 0; i < _length; i++) {
            road[i] = false;
        }

        return road;
    }

    std::string toString() {
        std::string result;

        result.append("[");

        for (int i = 0; i < roadLength; i++) {
            bool occupied = checkPosition(i, 0);
            result.append(occupied? "1" : "0");
            result.append(i < roadLength - 1? " " : "");
        }

        result.append("]");

        return result;
    }

    private:

    // == MÉTODOS PRIVADOS == //

    void iterationStep() {
        // //PARALELIZA AQ PO
        for (int i = 0; i < carCount; i++) {
            cars[i].move(road);
            //cars[i].updatePosition();
        }

        // TODO: FAZER!!!!!!!!!!!!!!!!!!!!!!!!!! (com convicção) *#*#*#*#*##*#*#*##*#*#*#*#*#*#*#*#**#*#*#*#*##*#*#*##*#*#*#*#*#*#*#*#**#*#*#*#*##*#*#*##*#*#*#*#*#*#*#*#*
        
        // for carros (paralelizado)
            // quer mudar de faixa.isCorreto()? faixa : faicha;
                // pode mudar faixa?
                    // marca road[posicao] = true

        // for carros (paralelizado)
            // atualiza velocidade (roadAnt[posicao + vel])
            // atualiza posicao
            // marca road[posicao] = true
        
        // roadAnt = road

        // ADO ADO ADO QUEM LER É GUEI
    }

    void printRoad(int iteration) {
        std::cout << "(" << iteration << ")\t" << toString() << std::endl;
    }

};