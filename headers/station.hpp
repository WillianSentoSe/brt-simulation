#ifndef STATION_HPP
#define STATION_HPP

class Station {

public:
    /* Public Variables */
    int id, x, size;

    /* Constructor */
    Station();
    Station(int id, int x);

    static std::list<Station> createStationsList(int, int);

    /* Utils */
    std::string toString();
};

#endif // STATION_HPP