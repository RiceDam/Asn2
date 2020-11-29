//
// Created by eric on 2020-11-27.
//
#include "city.hpp"

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
    if (x >= 0 && x <= 1000 && y >=0 && y <=1000) {
        x = x1;
        y = y1;
    }
}

void City::setName(std::string name1) {
    name = name1;
}

City::City(std::string name1) {
    name = name1;
    x = rand() % 1001;
    y = rand() % 1001;
}

