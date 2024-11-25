#pragma once
#include <iostream>
#include <string>
#include "BasePopulationHandler.hpp"

class MutationHandler : public BasePopulationHandler {
    int MUTATION_RATE{};
public:
    /**
        Creates two sets of "Parent" tours and crosses them to generate new tours
        :param population: a vector of candidate tours
        :return: a tuple where the first element is a string stating the
        outcome and the reason, and the second a bool indicating
        successful handling of the form or not.
     */
    MutationHandler() = default;

    /**
     * Single param constructor: sets the mutation rate
     * @param mutation_rate approximately the percent chance that each city in the tours of the population that gets
     * mutated has of being swapped with its neighbour
     */
    explicit MutationHandler(const int mutation_rate):MUTATION_RATE(mutation_rate){}

    /**
     * Holds the population during the mutation step
     */
    std::vector<Tour> mutation_population;

    /**
     * The Mutation Handler's handle_population performs the mutation step of the genetic algorithm.
     *
     * @param population the original population. Once mutation has occurred, gets replaced with mmutated population.
     * @return a pair of message and boolean to determine if there was an issue or if there are no more handlers in the
     * chain of responsibility
     */
    std::pair<std::string,bool> handle_population(std::vector<Tour> * population) override;

};