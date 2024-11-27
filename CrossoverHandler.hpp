#pragma once
#include <iostream>
#include "BasePopulationHandler.hpp"

/**
 * Crossover Handler
 *
 * Accepts a vector of tours and generates a new vector of tours
 * by "crossing" randomly chosen "parent" tours to make new tours
 */
class CrossoverHandler : public BasePopulationHandler {

    static const int ONE;
    static const int TWO;
    static const int PARENT_POOL_SIZE;

    std::vector<Tour> crossover_population;

public:
    /**
        Creates two sets of "Parent" tours and crosses them to generate new tours
        :param population: a vector of candidate tours
        :return: a bool indicating successful handling of the population or not.
     */
    CrossoverHandler() = default;

    bool handle_population(std::vector<Tour> *population) override;

    void generate_child(std::vector<Tour> * population, size_t size);
};