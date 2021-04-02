class Car {
    
    public:
    int id;
    int speed;
    int size;
    int x;
    int y;

    /* == CONSTRUTORES == */

    Car() {}

    Car(Configuration _config){
        speed = _config.initialCarSpeed;
        size = _config.defaultCarSize;
        id = 0; // TODO: gerar novo ID 
        x = UNDEFINED;
        y = UNDEFINED;
    }

    /* == MÉTODOS ESTÁTICOS == */

    static Car* createArrayOfCars(int _size, Configuration _config) {
        Car* array = (Car*) malloc(sizeof(Car) * _size);

        for(int i = 0; i < _size; i++) {
            array[i] = Car(_config);
        }

        return array;
    }

    /* == MÉTODOS PUBLICOS == */

    std::string toString() {
        std::string result;

        result.append("Car [");
        result.append(std::to_string(id));
        result.append("] = { POS = (");
        result.append(std::to_string(x));
        result.append(", ");
        result.append(std::to_string(y));
        result.append(") | VEL = (");
        result.append(std::to_string(speed));
        result.append(") }");

        return result;
    } 
};