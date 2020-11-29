//
// Created by eric on 2020-11-27.
//
#include "tour.hpp"
#include <math.h>

void Tour::calculateFitness() {
    fitness = 0;
    for (int i = 0; i < cities.size()-1; i++) {
        int a = cities[i].getX()^2 + cities[i+1].getX()^2;
        int b = cities[i].getY()^2 + cities[i+1].getY()^2;
        fitness += std::sqrt(a+b);
    }
}

Tour::Tour(const std::vector<City> &cities) : cities(cities) {
    calculateFitness();
}

