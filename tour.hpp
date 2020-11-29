//
// Created by eric on 2020-11-27.
//
#ifndef ASN2_TOUR_HPP
#define ASN2_TOUR_HPP


#include <vector>
#include "city.hpp"

class Tour {
private:
    std::vector<City> cities;
    int fitness;
public:
    Tour(const std::vector<City> &cities);

    void calculateFitness();
};


#endif //ASN2_TOUR_HPP
