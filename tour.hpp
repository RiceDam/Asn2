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
    double fitness;
public:
    Tour(const std::vector<City> &cities);
    Tour(const Tour &t2);

    void calculateFitness();

    const std::vector<City> &getCities() const;

    std::vector<City> &getModifiableCities();

    double getFitness() const;

    void setCities(const std::vector<City> &cities);
    friend bool operator == (const Tour &a,const Tour &b);
};


#endif //ASN2_TOUR_HPP
