#include "../../headers/station.hpp"

Station::Station(int _id, int _x) {
    id = _id;
    x = _x;
    size = 2;
}

Station::Station() {}

Station* Station::createStationsList(int _size, int _roadLenght) {
    Station* stations = (Station*) malloc(sizeof(Station) * _size);

    for (int i = 0; i < _size; i++) {
        Station station(i, (_roadLenght / _size / 2) + (i * (_roadLenght / _size - 1)));
        print(station.toString());
        stations[i] = station;
    }
    // std::list<Station> newList(0);

    // for(int i = 0; i < _size; i++) {
    //     Station station(i, (_roadLenght / _size / 2) + (i * (_roadLenght / _size - 1)));
    //     print(station.toString());
    //     newList.insert(newList.end(), station);
    // }

    // return newList;
    return stations;
}

std::string Station::toString() {
    std::string result;

    result.append("Station [");
    result.append(std::to_string(id));
    result.append("] = { POS = (");
    result.append(std::to_string(x));
    result.append(") }");

    return result;
}