#pragma once
#include "tour.hpp"

/**
 * The Tour Population Factory is responsible for creating a population of tours.
 *
 * The population returned by the createPopulation method is pre-sorted in increasing level of fitness.
 *
 * The calling class will be responsible for deallocating the memory allocated within the createPopulation method.
 */
class TourPopulationFactory {
    tour* t;
    int cities_in_tour{};
    int population_size{};

    /**
     * Constructor
     *
     * Will allow the user to assign the number of cities, the population size
     */
    explicit TourPopulationFactory(tour * t);

    /**
     * Create Population
     *
     * Returns a population of tours, pre-sorted in increasing level of fitness.
     *
     * @return a population of tours sorted in increasing level of fitness, as a vector of pointers to tour
     */
    std::vector<tour*> createPopulation() const;
};