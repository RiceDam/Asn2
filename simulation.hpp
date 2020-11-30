//
// Created by eric on 2020-11-27.
//
#ifndef ASN2_SIMULATION_HPP
#define ASN2_SIMULATION_HPP


#include "population.hpp"

class Simulation {
private:
    Population population;
    double baseDistance;
    double bestDistance;
    double improvement_factor = 0.4;
public:
    const int ITERATIONS = 1000;
    void simulate();
};


#endif //ASN2_SIMULATION_HPP
