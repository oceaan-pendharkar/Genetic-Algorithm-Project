#pragma once
#include "Tour.hpp"

/**
 * The Tour Population Factory is responsible for creating a population of tours.
 *
 * The population returned by the createPopulation method is pre-sorted in increasing level of fitness.
 *
 * The calling class will be responsible for deallocating the memory allocated within the createPopulation method.
 */
class TourPopulationFactory {
    int cities_in_tour{};
    int population_size{};

public:
    /**
     * Constructor
     *
     * Will allow the user to assign the number of cities, the population size
     */
    TourPopulationFactory();

    /**
     * Create Population
     *
     * Returns a population of tours, pre-sorted in increasing level of fitness.
     *
     * @return a population of tours sorted in increasing level of fitness, as a vector of pointers to tour
     */
    std::vector<Tour*> createPopulation() const;
};