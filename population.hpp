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
    int position = 0;
public:
    Population();
    const int POPULATION_SIZE = 32;
    const int CITIES_IN_TOUR = 32;
    const int PARENT_POOL_SIZE = 5;
    const int MUTATION_RATE = 15;
    const int NUMBER_OF_ELITES = 1;
    const int NUMBER_OF_PARENTS = 5;
    void generateCities();
    void generateTours();
    const std::vector<Tour> &getTours() const;
    void crossOver();
    void moveToFront();
    std::vector<Tour> chooseSubset();
    Tour chooseFittest(std::vector<Tour> &subset);
    void mutate(Tour &mutation);

    Tour crossParents(Tour &parent1, Tour &parent2);
};


#endif //ASN2_POPULATION_HPP
