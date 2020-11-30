//
// Created by eric on 2020-11-27.
//
#include <iostream>
#include "simulation.hpp"

void Simulation::simulate() {
    int i = 0;
    int improvements = 0;
    bestDistance = 1;
    baseDistance = 1;
    while (i < ITERATIONS || (((bestDistance/baseDistance) > improvement_factor) && improvements < 3000)) {
        std::cout << "Iteration: " << i << std::endl;
        population.moveToFront();
        std::cout << "Current Distance: " << population.getTours().front().getFitness() << std::endl;
        if (i == 0) {
            baseDistance = population.getTours().front().getFitness();
            bestDistance = baseDistance;
        }
        std::cout << "Best Distance: " << bestDistance << std::endl;
        if (bestDistance > population.getTours().front().getFitness()) {
            bestDistance = population.getTours().front().getFitness();
            std::cout << "Improvement" << std::endl;
            improvements = 0;
        } else {
            std::cout << "No Improvement" << std::endl;
            improvements++;
        }
        double overBase = baseDistance - bestDistance;
        std::cout << "Improvement over base: " << overBase << std::endl;
        population.crossOver();
        i++;
        std::cout << std::endl;
    }
}


