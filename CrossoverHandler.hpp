#pragma once
#include <iostream>
#include <string>
#include "BasePopulationHandler.hpp"

class CrossoverHandler : BasePopulationHandler {
    /*
        Creates two sets of "Parent" tours and crosses them to generate new tours
        :param population: a vector of candidate tours
        :return: a tuple where the first element is a string stating the
        outcome and the reason, and the second a bool indicating
        successful handling of the form or not.
     */
    CrossoverHandler() = default;

    std::pair<std::string,bool> handle_population(std::vector<Tour*> * population) override {
        std::cout << "Crossing population to make new tours" << std::endl;

        // Handler logic
        if () {

            //if no more handlers exist, return with success message
            if (!next_handler)
                return std::make_pair("", true);

            //else call next handler in sequence
            return next_handler->handle_population(population);
            }
        else
            //failed validation, return failure message
                return std::make_pair("Unable to Crossover population", false);
    }
};