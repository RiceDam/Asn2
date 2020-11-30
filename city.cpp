//
// Created by eric on 2020-11-27.
//
#include "city.hpp"
#include <random>
#include <ctime>

const std::string &City::getName() const {
    return name;
}

int City::getX() const {
    return x;
}

int City::getY() const {
    return y;
}

void City::setCoordinates(int x1, int y1) {
    if (x1 >= 0 && x1 <= 1000 && y1 >=0 && y1 <=1000) {
        x = x1;
        y = y1;
    }
}

void City::setName(std::string name1) {
    name = name1;
}

City::City(std::string name1) {
    name = name1;
    static std::random_device rd;
    static std::default_random_engine rng(rd());
    static std::uniform_int_distribution<> dis(0, MAP_BOUNDARY);
    setCoordinates(dis(rng), dis(rng));
}

void City::operator=(const City &c) {
    x = c.x;
    y = c.y;
    name = c.name;
}

bool operator==(const City &a, const City &b) {
    if (a.getX() == b.getX() && a.getY() == b.getY()
        && a.getName().compare(b.getName()) == 0) {
        return true;
    }
    return false;
}

bool operator!=(const City &a, const City &b) {
    return !(a==b);
}

void City::swap(City &other) {
    using std::swap;
    swap(this->name, other.name);
    swap(this->x, other.x);
    swap(this->y, other.y);
}

