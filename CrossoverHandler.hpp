#pragma once
#include <iostream>
#include <string>
#include "BasePopulationHandler.hpp"

class CrossoverHandler : public BasePopulationHandler {

    static const int ONE;
    static const int TWO;
    static const int PARENT_POOL_SIZE;

    std::vector<Tour> crossover_population;

public:
    /*
        Creates two sets of "Parent" tours and crosses them to generate new tours
        :param population: a vector of candidate tours
        :return: a tuple where the first element is a string stating the
        outcome and the reason, and the second a bool indicating
        successful handling of the form or not.
     */
    CrossoverHandler() = default;

    std::pair<std::string,bool> handle_population(std::vector<Tour> * population) override;

    void generate_child(std::vector<Tour> * population, size_t size);
};