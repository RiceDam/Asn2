//
// Created by eric on 2020-11-27.
//
#include "tour.hpp"
#include <cmath>

void Tour::calculateFitness() {
    fitness = 0;
    for (int i = 0; i < cities.size()-1; i++) {
        int a = cities[i].getX() - cities[i+1].getX();
        int b = cities[i].getY() - cities[i+1].getY();
        fitness += std::sqrt(pow(a,2)+pow(b,2));
    }
}

Tour::Tour(const std::vector<City> &cities) : cities(cities) {
    calculateFitness();
}

std::vector<City> &Tour::getModifiableCities() {
    return cities;
}

double Tour::getFitness() const {
    return fitness;
}

Tour::Tour(const Tour &t2) {
    cities = t2.cities;
    fitness = t2.fitness;
}

void Tour::setCities(const std::vector<City> &cities) {
    Tour::cities = cities;
}

bool operator==(const Tour &a, const Tour &b) {
    for (int i = 0; i < a.getCities().size(); i++) {
        if (a.getCities().at(i) != b.getCities().at(i)) {
            return false;
        }
    }
    return true;
}

const std::vector<City> &Tour::getCities() const {
    return cities;
}

