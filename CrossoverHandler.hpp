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

    /**
     * Handle population handles the population at each node. Crosses two parents and generates child tours for the
     * whole population.
     *
     * @param population the current population of tours
     * @return the next handler or true if ran successfully, else false
     */
    bool handle_population(std::vector<Tour> *population) override;

    /**
     * Generate child generates a child tour from two tour parents.
     * @param population the current population of tours
     * @param size the size of the tour
     */
    void generate_child(std::vector<Tour> * population, size_t size);
};