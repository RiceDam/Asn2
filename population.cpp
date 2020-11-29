//
// Created by eric on 2020-11-27.
//
#include "population.hpp"

void Population::generateCities() {
    for (int i = 0; i < CITIES_IN_TOUR; i++) {
        cityList.emplace_back("City" + std::to_string(i));
    }
}

void Population::generateTours() {
    generateCities();
    for (int i = 0; i < POPULATION_SIZE; i++) {
        tours.emplace_back(cityList);
    }
}
