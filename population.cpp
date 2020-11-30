//
// Created by eric on 2020-11-27.
//
#include <random>
#include <algorithm>
#include <iostream>
#include "population.hpp"

void Population::generateCities() {
    for (int i = 0; i < CITIES_IN_TOUR; i++) {
        cityList.emplace_back("City" + std::to_string(i));
    }
}

void Population::generateTours() {
    generateCities();
    static std::random_device rd;
    auto rng = std::default_random_engine{rd()};
    for (int i = 0; i < POPULATION_SIZE; i++) {
        tours.emplace_back(cityList);
        std::shuffle(cityList.begin(), cityList.end(), rng);
    }
}

Population::Population() {
    generateTours();
}

const std::vector<Tour> &Population::getTours() const {
    return tours;
}

void Population::crossOver() {
    static std::random_device rd;
    static std::default_random_engine rng(rd());
    static std::uniform_int_distribution<> dis(0, NUMBER_OF_PARENTS - 1);
    std::vector<Tour> parents;
    int numOfParents = 0;
    while (numOfParents < NUMBER_OF_PARENTS) {
        std::vector<Tour> temp = chooseSubset();
        Tour tempTour = chooseFittest(temp);
        if (std::find(parents.begin(), parents.end(), tempTour) == parents.end()) {
            parents.emplace_back(tempTour);
            numOfParents++;
        }
    }
    for (int i = NUMBER_OF_ELITES; i < tours.size(); i++) {
        tours.at(i) = crossParents(parents.at(dis(rng)), parents.at(dis(rng)));
        mutate(tours.at(i));
        tours.at(i).calculateFitness();
    }
}

void Population::moveToFront() {
    double max = getTours().front().getFitness();
    int pos = 0;
    for (int i = 0; i < tours.size(); i++) {
        if (tours.at(i).getFitness() < max) {
            max = tours.at(i).getFitness();
            pos = i;
        }
    }
    Tour temp = tours.at(pos);
    tours.erase(tours.begin() + pos);
    tours.insert(tours.begin(), temp);
}

std::vector<Tour> Population::chooseSubset() {
    static std::random_device rd;
    static std::default_random_engine rng(rd());
    static std::uniform_int_distribution<> dis(NUMBER_OF_ELITES, tours.size() - 1);
    std::vector<Tour> subset;
    int i = 0;
    while (i < PARENT_POOL_SIZE) {
        Tour temp = tours.at(dis(rng));
        if (std::find(subset.begin(), subset.end(), temp) == subset.end()) {
            subset.emplace_back(temp);
            i++;
        }
    }
    return subset;
}

Tour Population::chooseFittest(std::vector<Tour> &subset) {
    double max = subset.front().getFitness();
    int pos = 0;
    for (int i = 0; i < subset.size(); i++) {
        if (subset.at(i).getFitness() < max) {
            max = subset.at(i).getFitness();
            pos = i;
        }
    }
    return subset.at(pos);
}

Tour Population::crossParents(Tour &parent1, Tour &parent2) {
    static std::random_device rd;
    static std::default_random_engine rng(rd());
    static std::uniform_int_distribution<> dis(0, CITIES_IN_TOUR - 1);
    std::vector<City> tempCityList;
    int random = dis(rng);
    for (int i = 0; i < random; i++) {
        tempCityList.emplace_back(parent1.getCities().at(i));
    }
    int j = 0;
    while (tempCityList.size() < CITIES_IN_TOUR) {
        City tempCity = parent2.getCities().at(j++);
        if (std::find(tempCityList.begin(), tempCityList.end(), tempCity) == tempCityList.end()) {
            tempCityList.emplace_back(tempCity);
        }
    }
    return Tour(tempCityList);
}

void Population::mutate(Tour &mutated) {
    static std::random_device rd;
    static std::default_random_engine rng(rd());
    static std::uniform_int_distribution<> dis(0, CITIES_IN_TOUR - NUMBER_OF_ELITES-1);

    static std::random_device rd2;
    static std::default_random_engine cityRNG(rd2());
    static std::uniform_int_distribution<> disCity(0, 100);

    static std::random_device rd3;
    static std::default_random_engine choiceRNG(rd3());
    static std::uniform_int_distribution<> disChoice(0, 1);

    for (int j = 0; j < mutated.getCities().size(); j++) {
        int mutate = disCity(cityRNG);
        if (mutate < MUTATION_RATE) {
            int randNum = dis(rng);
            if (disChoice(choiceRNG) == 0) {
                if (randNum != mutated.getCities().size() - 1) {
                    mutated.getModifiableCities().at(randNum).swap(
                            mutated.getModifiableCities().at(randNum+1));
                } else {
                    mutated.getModifiableCities().at(randNum).swap(
                            mutated.getModifiableCities().at(randNum-1));
                }
            }
            else if (disChoice(choiceRNG) == 1) {
                if (randNum != 0) {
                    mutated.getModifiableCities().at(randNum).swap(
                            mutated.getModifiableCities().at(randNum - 1));
                } else {
                    mutated.getModifiableCities().at(randNum).swap(
                            mutated.getModifiableCities().at(randNum + 1));
                }
            }
        }
    }
}


