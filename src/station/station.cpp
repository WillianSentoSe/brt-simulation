#include "../../headers/station.hpp"

Station::Station(int _id, int _x) {
    id = _id;
    x = _x;
}

Station::Station() {}

std::list<Station> Station::createStationsList(int _size) {
    std::list<Station> newList(0);

    for(int i = 0; i < _size; i++) {
        Station station(i, 0);
        newList.insert(newList.end(), station);
    }

    return newList;
}

std::string Station::toString() {
    std::string result;

    result.append("Station [");
    result.append(std::to_string(id));
    result.append("] = { POS = (");
    result.append(std::to_string(x));
    result.append(")");

    return result;
}