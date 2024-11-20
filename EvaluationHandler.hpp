#pragma once
#include <iostream>
#include <string>
#include "BasePopulationHandler.hpp"

class EvaluationHandler : BasePopulationHandler {
    /*
        Evaluates the mutated
        :return: a tuple where the first element is a string stating the
        outcome and the reason, and the second a bool indicating
        successful handling of the form or not.
     */
    EvaluationHandler() = default;

    std::pair<std::string,bool> handle_population(std::vector<Tour*> * population) override {
        std::cout << "Evaluating crossed and mutated population" << std::endl;

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
                return std::make_pair("Unable to evaluate population", false);
    }
};