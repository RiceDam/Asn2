//
// Created by eric on 2020-11-27.
//
#ifndef ASN2_POPULATION_HPP
#define ASN2_POPULATION_HPP


#include <vector>
#include "tour.hpp"

class Population {
private:
    std::vector<Tour> tours;
    std::vector<City> cityList;
public:
    const int POPULATION_SIZE = 32;
    void generateCities();
    void generateTours();
    const int CITIES_IN_TOUR = 32;
};


#endif //ASN2_POPULATION_HPP
